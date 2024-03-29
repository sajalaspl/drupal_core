<?php
// $Id: views_handler_sort_ncs_last_updated.inc,v 1.1 2010/06/29 07:05:41 sajal Exp $
/**
 * Sort handler for the newer of last comment / node updated
 */
class views_handler_sort_ncs_last_updated extends views_handler_sort_date {
  function query() {
    $this->ensure_my_table();
    $this->node_table = $this->query->ensure_table('node', $this->relationship);
    $this->field_alias = $this->query->add_orderby(NULL, "GREATEST(" . $this->node_table . ".changed, " . $this->table_alias . ".last_comment_timestamp)", $this->options['order'], $this->table_alias . '_' . $this->field);
  }
}

