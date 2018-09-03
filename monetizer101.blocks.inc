<?php

/**
 * @file Code to do with blocks.
 */

/**
 * Implements hook_block_info().
 *
 * Full listing needs to be a block so it can be placed in a region.
 */
function monetizer101_block_info() {
  $blocks['monetizer101_full'] = array(
    'info' => t('Monetizer101 Full'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['monetizer101_summary'] = array(
    'info' => t('Monetizer101 Summary'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['monetizer101_sticky'] = array(
    'info' => t('Monetizer101 Sticky'),
    'cache' => DRUPAL_NO_CACHE,
  );

  return $blocks;
}

/**
 * Implements hook_block_configure().
 */
function monetizer101_block_configure($delta = '') {
  $form = array();

  // Get all the blocks defined by this module.
  $blocks = monetizer101_block_info();

  if (isset($blocks[$delta])) {
    $form = monetizer101_block_settings_form($delta);
  }

  return $form;
}

/**
 * Implements hook_block_save().
 */
function monetizer101_block_save($delta = '', $edit = array()) {
  // Get all the blocks defined by this module.
  $blocks = monetizer101_block_info();

  if (isset($blocks[$delta])) {
    foreach ($edit as $name => $value) {
      // If the param name starts with the block name,
      // we know it's a m101 setting.
      if (strpos($name, $delta) === 0) {
        variable_set($name, $value);
      }
    }
  }
}

/**
 * Generate a m101 settings form for the block.
 *
 * @param string $block_name
 *   The name of the block.
 *
 * @return array
 *   The generated form array.
 */
function monetizer101_block_settings_form($block_name) {
  $form = array(
    'monetizer101_settings' => array(
      '#type' => 'fieldset',
      '#title' => t('Monetizer101 Settings'),
      $block_name . '_template_id' => array(
        '#type' => 'textfield',
        '#title' => t('Template ID'),
        '#default_value' => variable_get($block_name . '_template_id', ''),
      ),
      $block_name . '_price_range' => array(
        '#type' => 'textfield',
        '#title' => t('Price Range'),
        '#description' => t('Price range to fetch relevant result in percentage.  E.g. 30 is 30% (if price is £100 then range will be £70-£130).'),
        '#default_value' => variable_get($block_name . '_price_range', ''),
      ),
      $block_name . '_merchant_number' => array(
        '#type' => 'textfield',
        '#title' => t('Merchant number'),
        '#description' => t('The amount of results from each merchant to use. (Leave blank to show unlimited results from each merchant)'),
        '#default_value' => variable_get($block_name . '_merchant_number', ''),
      ),
      $block_name . '_sorting_field' => array(
        '#type' => 'textfield',
        '#title' => t('Field to use for sorting.'),
        '#description' => t('The amount of results from each merchant to use. (Leave blank to show unlimited results from each merchant)'),
        '#default_value' => variable_get($block_name . '_sorting_field', 'PRICE'),
      ),
      $block_name . '_sorting_order' => array(
        '#type' => 'select',
        '#title' => t('Sorting Order'),
        '#options' => array('asc' => t('Ascending'), 'desc' => t('Descending')),
        '#default_value' => variable_get($block_name . '_sorting_order', 'asc'),
      ),
    ),
  );

  return $form;
}

/**
 * Implements hook_block_view().
 */
function monetizer101_block_view($delta = '') {
  $block = array();

  if (in_array($delta, array_keys(monetizer101_block_info()))) {
    if ($node = menu_get_object()) {
      if ($data = monetizer101_get_widget_data($node, $delta)) {
        $block['content'] = array(
          '#theme' => 'monetizer101_widget',
          '#widget_name' => $delta,
        );
      }
    }
  }

  if (empty($data)) {
    return;
  }

  switch ($delta) {
    case 'monetizer101_full':
      $block['content']['#data_config'] = array(
        'nameKeywords' => $data['nameKeywords'],
        'price' => $data['price'],
        'delta' => $data['delta'],
        'sid' => 'full',
        'resultLimit' => 10,
      );
      break;

    case 'monetizer101_summary':
      $block['content']['#data_config'] = array(
        'nameKeywords' => $data['nameKeywords'],
        'price' => $data['price'],
        'delta' => $data['delta'],
        'sid' => 'summary',
        'resultLimit' => 3,
      );
      break;

    case 'monetizer101_sticky':
      $block['content']['#data_config'] = array(
        'nameKeywords' => $data['nameKeywords'],
        'price' => $data['price'],
        'delta' => $data['delta'],
        'sid' => 'sticky',
        'resultLimit' => 1,
      );
      $block['content']['#attached']['js'][] =  drupal_get_path('module', 'monetizer101') . '/js/monetizer101Sticky.js';
      break;

    default:
      break;
  }

  return $block;
}


/**
 * Implements hook_block_view_alter().
 */
function monetizer101_block_view_alter(&$data, $block) {

  if ($block->module == 'monetizer101') {
    // Get current node object so we can see if it has been flagged.
    if ($node = menu_get_object()) {
      $disable_mod_widgets = flag_get_flag('disable_monetizer_widgets')->is_flagged($node->nid);
    }
    else {
      return;
    }

    if ($disable_mod_widgets) {
      switch ($block->delta) {
        case 'monetizer101_full':
          unset($data['content']);
          break;
        case 'monetizer101_sticky':
          unset($data['content']);
          break;
        case 'monetizer101_summary':
          unset($data['content']);
          break;
      }
    }
  }
}
