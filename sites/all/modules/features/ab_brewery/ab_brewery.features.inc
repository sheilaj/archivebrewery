<?php
/**
 * @file
 * ab_brewery.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function ab_brewery_flag_default_flags() {
  $flags = array();
  // Exported flag: "Incomlete".
  $flags['incomlete'] = array(
    'entity_type' => 'node',
    'title' => 'Incomlete',
    'global' => 1,
    'types' => array(
      0 => 'beer',
      1 => 'brewery',
      2 => 'item',
    ),
    'flag_short' => 'Flag this item as incomplete',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag - Completed',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'ab_brewery',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function ab_brewery_node_info() {
  $items = array(
    'brewery' => array(
      'name' => t('Brewery'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
