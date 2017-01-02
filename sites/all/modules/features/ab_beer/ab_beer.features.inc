<?php
/**
 * @file
 * ab_beer.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ab_beer_node_info() {
  $items = array(
    'beer' => array(
      'name' => t('Beer'),
      'base' => 'node_content',
      'description' => t('A beer, e.g. Fat Tug'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
