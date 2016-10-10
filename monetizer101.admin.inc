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

  $form['monetizer101_shop_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Shop ID'),
    '#description' => t('Your Monetizer101 shop ID.'),
    '#default_value' => variable_get('monetizer101_shop_id', ''),
    '#required' => TRUE,
  );

  $form['monetizer101_currency_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Currency Code'),
    '#description' => t('Set the default currency code.  Note if geolocation is turned on this will override it (when available).'),
    '#default_value' => variable_get('monetizer101_currency_code', ''),
    '#required' => TRUE,
  );

  $form['monetizer101_language_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Language Code'),
    '#description' => t('Set the default language code.  Note if geolocation is turned on this will override it (when available).'),
    '#default_value' => variable_get('monetizer101_language_code', 'en'),
    '#required' => TRUE,
  );

  $form['monetizer101_geolocation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Geolocation'),
    '#description' => t('Enable Monetizer101 geodetection.'),
    '#default_value' => variable_get('monetizer101_geolocation', TRUE),
  );

  $form['monetizer101_template_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Template ID'),
    '#description' => t('Set the widget template id (grab this from the generated json config).'),
    '#default_value' => variable_get('monetizer101_template_id', ''),
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

  $form['monetizer101_merchant_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Merchant Number'),
    '#description' => t('The amount of results from each merchant to use. (Leave blank to show unlimited results from each merchant)'),
    '#default_value' => variable_get('monetizer101_merchant_number', ''),
  );

  $form['monetizer101_sorting_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Sorting Field'),
    '#description' => t('Field to use for sorting.'),
    '#default_value' => variable_get('monetizer101_sorting_field', 'PRICE'),
    '#required' => FALSE,
  );

  $form['monetizer101_sorting_order'] = array(
    '#type' => 'select',
    '#title' => t('Sorting Order'),
    '#options' => array('asc' => t('Ascending'), 'desc' => t('Descending')),
    '#default_value' => variable_get('monetizer101_sorting_order', 'asc'),
  );

  return system_settings_form($form);
}
