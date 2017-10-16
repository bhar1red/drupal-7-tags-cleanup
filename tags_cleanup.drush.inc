<?php

/**
 * Implements hook_drush_command().
 */
function tags_cleanup_drush_command() {
  $items['tags_cleanup_clean'] = array(
    'description' => 'To clean tags',
    'access arguments' => array('access content'),
    'aliases' => array('tgc')
  );
  return $items;
}

function drush_tags_cleanup_clean(){
  tags_cleanup_execute();
  return;
}
