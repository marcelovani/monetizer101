<?php

/**
 * @file
 * ReevooMark administration pages.
 */

/**
 * Returns with the general configuration form.
 *
 * @ingroup forms
 * @see system_settings_form()
 *
 * @param array $form
 *   A Drupal form.
 * @param array $form_state
 *   The current state of the form.
 *
 * @return array
 *   Output of the system_settings_form()
 *
 */
function monetizer101_admin_settings($form, &$form_state) {
  $form['monetizer101_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Api Key'),
    '#description' => t('Api key to connect to monetizer101'),
    '#default_value' => variable_get('monetizer101_api_key', ''),
    '#required' => TRUE,
  );

  $form['monetizer101_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Api url'),
    '#description' => t('Api url to connect to monetizer101'),
    '#default_value' => variable_get('monetizer101_api_url', ''),
    '#required' => TRUE,
  );

  $form['monetizer101_price_range'] = array(
    '#type' => 'textfield',
    '#title' => t('Price Range'),
    '#description' => t('Price range to fetch relevant result. e.g 0.3  is 30% up and down of product price'),
    '#default_value' => variable_get('monetizer101_price_range', '0.3'),
    '#required' => TRUE,
  );

  $form['monetizer101_full_listing_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('full Listing Limit'),
    '#description' => t('Limit on number of result to get for full listing'),
    '#default_value' => variable_get('monetizer101_full_listing_limit', '10'),
    '#required' => TRUE,
  );

  $form['moetizer101_summary_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('summary Listing Limit'),
    '#description' => t('Limit on number of result for summary listing'),
    '#default_value' => variable_get('moetizer101_summary_limit', '4'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
