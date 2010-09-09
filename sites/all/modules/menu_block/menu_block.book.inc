<?php
// $Id: menu_block.book.inc,v 1.1 2010/08/31 05:30:10 sanjaym Exp $

/**
 * @file
 * Provides book integration.
 */

/**
 * Implements hook_get_menus().
 */
function book_get_menus() {
  $menus = array();
  foreach (book_get_books() AS $book) {
    $menus[$book['menu_name']] = $book['title'];
  }
  return $menus;
}
