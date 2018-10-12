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

  $form['monetizer101']['monetizer101_js_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Javascript URL'),
    '#description' => t('The url of the javascript, provided by Monetizer.'),
    '#default_value' => variable_get('monetizer101_js_url'),
    '#required' => TRUE,
  );

  $form['monetizer101']['monetizer101_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Domain'),
    '#description' => t('Your Monetizer101 domain. Leave this empty if you are using https and you are using init-library.js in the field above.'),
    '#default_value' => variable_get('monetizer101_domain', ''),
    '#required' => FALSE,
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

  $block_machine_names = array_keys(monetizer101_block_info());
  foreach ($block_machine_names as $key) {
    $current_template_options[$key] = $key;
  }
  $form['monetizer101']['monetizer101_current_block'] = array(
    '#type' => 'select',
    '#options' => $current_template_options,
    '#title' => t('Template'),
    '#description' => 'Machine name of the template you want to use. This field is used only if domain is empty.',
    '#default_value' => variable_get('monetizer101_current_block', 'monetizer101_full'),
    '#required' => FALSE,
  );

  $form['monetizer101']['monetizer101_geolocation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Geolocation'),
    '#description' => t('Enable Monetizer101 geodetection.'),
    '#default_value' => variable_get('monetizer101_geolocation', TRUE),
  );

  $form['monetizer101']['monetizer101_use_require'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use RequireJS'),
    '#description' => t('Use RequireJS to load scripts.'),
    '#default_value' => variable_get('monetizer101_use_require', FALSE),
  );

  return system_settings_form($form);
}
