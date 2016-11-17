<?php

/**
 * @file
 * Monetizer101 administration pages.
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

  $form['monetizer101'] = array(
    '#type' => 'fieldset',
    '#title' => t('Monetizer101 Global Settings'),
    '#description' => t('For specific widget settings (such as templateID), please edit the block from the !block_config_page', array('!block_config_page' => l(t('block config page'), 'admin/structure/block'))),
  );

  $form['monetizer101']['monetizer101_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Base URL'),
    '#description' => t('Widget base URL.'),
    '#default_value' => variable_get('monetizer101_url', MONETIZER101_DEFAULT_BASE_URL),
  );

  $form['monetizer101']['monetizer101_shop_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Shop ID'),
    '#description' => t('Your Monetizer101 shop ID.'),
    '#default_value' => variable_get('monetizer101_shop_id', ''),
    '#required' => TRUE,
  );

  $form['monetizer101']['monetizer101_currency_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Currency Code'),
    '#description' => t('Set the default currency code.  Note if geolocation is turned on this will override it (when available).'),
    '#default_value' => variable_get('monetizer101_currency_code', ''),
    '#required' => TRUE,
  );

  $form['monetizer101']['monetizer101_language_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Language Code'),
    '#description' => t('Set the default language code.  Note if geolocation is turned on this will override it (when available).'),
    '#default_value' => variable_get('monetizer101_language_code', 'en'),
    '#required' => TRUE,
  );

  $form['monetizer101']['monetizer101_geolocation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Geolocation'),
    '#description' => t('Enable Monetizer101 geodetection.'),
    '#default_value' => variable_get('monetizer101_geolocation', TRUE),
  );

  return system_settings_form($form);
}
