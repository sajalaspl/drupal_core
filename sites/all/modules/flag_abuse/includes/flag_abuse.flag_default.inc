<?php
// $Id: flag_abuse.flag_default.inc,v 1.1 2010/07/24 07:30:33 sajal Exp $

function _flag_abuse_abuse_node_flags(&$flags) {
  $flags[] = array(
    'content_type' => 'node',
    'name' => 'abuse_node',
    'title' => 'Node Abuse',
    'roles' => array(
      0 => '2',
    ),
    'global' => FALSE,
    'flag_short' => 'Flag as offensive',
    'flag_long' => 'Flag this content as offensive.',
    'flag_confirmation' => 'Are you sure you want to flag this content as offensive?',
    'unflag_short' => 'Flag as non-offensive',
    'unflag_long' => 'Flag this content as non-offensive.',
    'unflag_confirmation' => 'Are you sure you want to flag this content as non-offensive?',
    'types' => array('story'),
    'status' => FALSE,
    'show_on_teaser' => FALSE,
    'link_type' => 'confirm',
    'locked' => array('name', 'global'),
  );
  return $flags;
}

function _flag_abuse_abuse_comment_flags(&$flags) {
  $flags[] = array(
    'content_type' => 'comment',
    'name' => 'abuse_comment',
    'title' => 'Comment Abuse',
    'roles' => array(
      0 => '2',
    ),
    'global' => FALSE,
    'flag_short' => 'Flag as offensive',
    'flag_long' => 'Flag this content as offensive.',
    'flag_confirmation' => 'Are you sure you want to flag this content as offensive?',
    'unflag_short' => 'Flag as non-offensive',
    'unflag_long' => 'Flag this content as non-offensive.',
    'unflag_confirmation' => 'Are you sure you want to flag this content as non-offensive?',
    'types' => array('story'),
    'status' => FALSE,
    'show_on_teaser' => FALSE,
    'link_type' => 'confirm',
    'locked' => array('name', 'global'),
  );
  return $flags;
}

function _flag_abuse_abuse_user_flags(&$flags) {
  $flags[] = array(
    'content_type' => 'user',
    'name' => 'abuse_user',
    'title' => 'User Abuse',
    'roles' => array(
      0 => '2',
    ),
    'global' => FALSE,
    'flag_short' => 'Report User',
    'flag_long' => 'Report this user as offensive.',
    'flag_confirmation' => 'Are you sure you want to report this user as offensive?',
    'unflag_short' => 'Remove Report',
    'unflag_long' => 'Remove your report about this user.',
    'unflag_confirmation' => 'Are you sure you want to remove your report of this user?',
    'status' => FALSE,
    'show_on_teaser' => FALSE,
    'link_type' => 'confirm',
    'locked' => array('name', 'global'),
  );
  return $flags;
}
