<?php

/**
 * @file
 * Monetizer101 block administration pages.
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

  $form['monetizer101_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => variable_get('monetizer101_enabled', 1),
    '#description' => 'Uncheck to stop Monetizer block showing.',
  );

  $form['monetizer101_script'] = array(
    '#type' => 'textarea',
    '#title' => t('M101 Widget script'),
    '#default_value' => variable_get('monetizer101_script', ''),
    '#description' => t("The maximum number of links to display in the block."),
  );

  return system_settings_form($form);
}
