<?php
// $Id: views_handler_field_node_new_comments.inc,v 1.1 2010/06/29 07:05:41 sajal Exp $

/**
 * Field handler to display the number of new comments
 */
class views_handler_field_node_new_comments extends views_handler_field_numeric {
  function init(&$view, $options) {
    parent::init($view, $options);
    
    // translate an older setting:
    if (!empty($options['no_empty'])) {
      $this->options['hide_empty'] = TRUE;
      unset($this->options['no_empty']);
    }
  }

  function construct() {
    parent::construct();
    $this->additional_fields = array('nid' => 'nid', 'type' => 'type');
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['link_to_comment'] = array('default' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_comment'] = array(
      '#title' => t('Link this field to new comments'),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['link_to_comment'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
    $this->field_alias = $this->table . '_' . $this->field;
  }

  function pre_render(&$values) {
    global $user;
    if (!$user->uid || empty($values)) {
      return;
    }

    $nids = array();
    $ids = array();
    foreach ($values as $id => $result) {
      $nids[] = $result->{$this->aliases['nid']};
      $values[$id]->{$this->field_alias} = 0;
      // Create a reference so we can find this record in the values again.
      if (empty($ids[$result->{$this->aliases['nid']}])) {
        $ids[$result->{$this->aliases['nid']}] = array();
      }
      $ids[$result->{$this->aliases['nid']}][] = $id;
    }

    if ($nids) {
      $result = db_query("SELECT n.nid, COUNT(c.cid) as num_comments FROM {node} n INNER JOIN {comments} c ON n.nid = c.nid LEFT JOIN {history} h ON h.nid = n.nid AND h.uid = %d WHERE n.nid IN (" . implode(', ', $nids) . ") AND c.timestamp > GREATEST(COALESCE(h.timestamp, %d), %d) AND c.status = %d GROUP BY n.nid  ", $user->uid, NODE_NEW_LIMIT, NODE_NEW_LIMIT, COMMENT_PUBLISHED);

      while ($node = db_fetch_object($result)) {
        foreach ($ids[$node->nid] as $id) {
          $values[$id]->{$this->field_alias} = $node->num_comments;
        }
      }

    }
  }

  function render_link($data, $values) {
    if (!empty($this->options['link_to_comment']) && $data !== NULL && $data !== '') {
      $node = new stdClass();
      $node->nid = $values->{$this->aliases['nid']};
      $node->type = $values->{$this->aliases['type']};
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'node/' . $node->nid;
      $this->options['alter']['query'] = comment_new_page_count($values->node_comment_statistics_comment_count, $values->node_new_comments, $node);
      $this->options['alter']['fragment'] = 'new';
    }

    return $data;
  }

  function render($values) {
    if (!empty($values->{$this->field_alias})) {
      return $this->render_link(parent::render($values), $values);
    }
    else {
      $this->options['alter']['make_link'] = FALSE;
    }
  }
}
