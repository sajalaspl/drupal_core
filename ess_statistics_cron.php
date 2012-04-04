<?php
// $Id: ess_statistics_cron.php,v 1.2 2012/04/04 12:48:21 sajal Exp $
/**
 * This cron script will execute at every mid-night. (11:55 pm). It will do following.
 * 
 *   (i) Copy all node view counts from "node_counter" to "node_counter_daywise".
 *  (ii) Move all records older than 40 days from "node_counter_daywise" to "node_counter_monthwise".
 * (iii) Remove all records from "node_counter_monthwise" older than 13 months.
 * 
 *  Need to create two mysql tables. Also need to create INDEXES.
 */
chdir(dirname(__FILE__));
require_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

/* error_reporting(E_ALL);
ini_set('display_errors', 1); */

// get today's date
$strTodayDate = date("Y-m-d");

// debugging purpose
$strSelectResult = db_query('SELECT node.nid, daycount, \'' . $strTodayDate .'\' as r_date 
  FROM {node_counter} node_counter INNER JOIN {node} node 
  ON node.nid = node_counter.nid
  AND (node.type = \'album_image\' OR node.type =  \'campaign_user\' OR node.type =  \'picture_vault_image\') 
  WHERE node_counter.daycount > 0');

$strResult = '<table border="1"><th>Node</th><th>Daycount</th><th>Date</th>';
if (db_affected_rows($strSelectResult)) {
  while ($row = db_fetch_object($strSelectResult)) {
  	$strResult .= '<tr>
                     <td>'.$row->nid.'</td>                     
                     <td>'.$row->daycount.'</td>
                     <td>'.$row->r_date.'</td>
  	               </tr>';
  }
} else {
  $strResult .= '<tr><td colspan="3">No node views found for today.</td></tr>';
}
$strResult .= '</table>';

// select/insert all records from "node_counter" => "node_counter_daywise" which has daycount > 0
db_query('INSERT INTO {node_counter_daywise} (nid, daycount, r_date)
  (SELECT node.nid, daycount, \'' . $strTodayDate .'\' as r_date 
  FROM {node_counter} node_counter INNER JOIN {node} node 
  ON node.nid = node_counter.nid
  AND (node.type = \'album_image\' OR node.type =  \'campaign_user\' OR node.type =  \'picture_vault_image\') 
  WHERE node_counter.daycount > 0 )');

// reset node daycounts in "node_counter" table
db_query("UPDATE {node_counter} SET daycount = '0'");

// adjust core statistics timestamp variable
variable_set('statistics_day_timestamp', time() + 3600);

// get all records from "node_counter_daywise" aggregated monthwise which are 
// older than 40 days
$result = db_query('SELECT nid, sum( daycount ) as total_month_count, 
  DATE_FORMAT( r_date, "%Y" ) AS year, DATE_FORMAT( r_date, "%m" ) AS
  month , DATE_FORMAT( r_date, "%Y-%m" ) AS month_year 
  FROM {node_counter_daywise} node_counter_daywise 
  WHERE node_counter_daywise.daycount > 0 
  AND UNIX_TIMESTAMP(r_date) < UNIX_TIMESTAMP(DATE_SUB(CURDATE(), INTERVAL 40 DAY))
  GROUP BY node_counter_daywise.nid, month_year
  ORDER BY r_date DESC
');

// insert all these records to "node_counter_monthwise" table
// debugging
$strResult .= '<br/><br/><table border="1"><th>NID</th><th>TotalCount</th><th>MonthYear</th>';
if (db_affected_rows($result)) {
  while ($row = db_fetch_object($result)) {
    // init date
    $intNid = $row->nid;
    $intMonthCount = $row->total_month_count;
    $intYear = $row->year;
    $intMonth = $row->month;
    
    // if entry exists "update" else "insert"
    $strQuery = "SELECT node_counter_monthwise.id 
      FROM {node_counter_monthwise} node_counter_monthwise WHERE 
      node_counter_monthwise.nid = '%d' AND node_counter_monthwise.r_month = '%d' 
      AND node_counter_monthwise.r_year = '%d'";
    $id = db_result(db_query($strQuery, $intNid, $intMonth, $intYear));

    if ($id) {
      db_query('UPDATE {node_counter_monthwise} node_counter_monthwise 
        SET node_counter_monthwise.monthcount = node_counter_monthwise.monthcount + %d
        WHERE node_counter_monthwise.id = %d', $intMonthCount, $id);
    } else {
      db_query('INSERT INTO {node_counter_monthwise} (nid, r_month, r_year, monthcount) 
        VALUES (%d, %s, %s, %d)', $intNid, $intMonth, $intYear, $intMonthCount);
    }
    
    // debugging
    $strResult .= '<tr>
                     <td>'.$intNid.'</td>                     
                     <td>'.$intMonthCount.'</td>
                     <td>'.$row->month_year.'</td>
  	               </tr>';
  }
} else {
  $strResult .= '<tr><td colspan="3">No records older than 40 days.</td></tr>';
}
$strResult .= '</table>';
 
// delete records older than 40 days from "node_counter_daywise" table as we have 
// moved it to "node_counter_monthwise" in above step
db_query('DELETE FROM {node_counter_daywise} WHERE 
  UNIX_TIMESTAMP(r_date) < UNIX_TIMESTAMP(DATE_SUB(CURDATE(), INTERVAL 40 DAY))');

// delete all records from "node_counter_monthwise" which are older than 1 year
db_query('DELETE FROM {node_counter_monthwise} WHERE 
  UNIX_TIMESTAMP(CONCAT(r_year, "-", r_month, "-", "01")) <= 
  UNIX_TIMESTAMP(DATE_SUB(CURDATE(), INTERVAL 13 MONTH))
  ');

// send mail for debugging purpose
$headers  = 'MIME-Version: 1.0' . "\r\n";
$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
@mail('sajal@aspl.in', 'ESS STATISTICS CRON RUN RESULT DATED ON '.$strTodayDate, 
    $strResult, $headers);
