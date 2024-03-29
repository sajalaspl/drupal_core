<?php
// $Id: views_handler_sort_comment_thread.inc,v 1.1 2010/06/29 07:05:41 sajal Exp $
/**
 * Sort handler for ordering by thread
 */
class views_handler_sort_comment_thread extends views_handler_sort {
  function query() {
    $this->ensure_my_table();

    //Read comment_render() in comment.module for an explanation of the
    //thinking behind this sort.
    if ($this->options['order'] == 'DESC') {
      $this->query->add_orderby($this->table_alias, $this->real_field, $this->options['order']);
    }
    else {
      $alias = $this->table_alias . '_' . $this->real_field . 'asc';
      //@todo is this secure?
      $this->query->add_orderby(NULL, "SUBSTRING({$this->table_alias}.{$this->real_field}, 1, (LENGTH({$this->table_alias}.{$this->real_field}) - 1))", $this->options['order'], $alias);
    }
  }
}
