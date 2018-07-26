<?php

/**
 * @file Code to do with flags.
 */

/**
 * Implements hook_flag_default_flags().
 */
function monetizer101_flag_default_flags() {
  $flags = array();

  $flags['disable_monetizer_widgets'] = array(
    'entity_type' => 'node',
    'title' => 'Disable M101 Widgets',
    'global' => 1,
    'types' => variable_get('monetizer101_disable_widgets_content_types', array(
      'article',
      'review',
    )),
    'flag_short' => 'Disable M101 Widgets',
    'flag_long' => 'Disable the M101 Widgets on this node',
    'flag_message' => 'M101 Widgets have been disabled on this node',
    'unflag_short' => 'Enable M101 Widgets',
    'unflag_long' => 'Enable the M101 Widgets on this node',
    'unflag_message' => 'The M101 Widgets have been enabled on this node',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 1,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'api_version' => 3,
  );

  return $flags;
}
