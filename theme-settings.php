<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function zurb_foundation_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['theme_ui'] = array(
    '#type' => 'details',
    '#title' => t('UI Elements'),
  );

  $form['theme_ui']['status_in_reveal'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display status messages in Reveal'),
    '#description' => t('This will display status messages in a Foundation Reveal modal instead of print them into the page output.'),
    '#default_value' => theme_get_setting('status_in_reveal', 'zurb_foundation'),
  );

  $form['theme_javascript'] = array(
    '#type' => 'details',
    '#title' => t('Javascript Files'),
  );

  $form['theme_javascript']['use_respondjs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Implement Respond.js'),
    '#description' => t('Foundation 4.x does not support IE8, but you can include Respond.js to add additional support for Internet Explorer.'),
    '#default_value' => theme_get_setting('use_respondjs', 'zurb_foundation'),
  );

  /*
   * Styles and Scripts
   */
  $form['styles_scripts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Styles and Scripts'),
    '#collapsible' => TRUE,
  );

  $form['styles_scripts']['disable_base_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Base Theme CSS'),
    '#description' => t('Disabling the base theme CSS is useful for using SASS in a sub-theme.<br><strong>If you select this option, uncomment the relevant CSS includes in your sub-theme\'s .info file.</strong>'),
    '#default_value' => theme_get_setting('disable_base_css', 'zurb_foundation'),
  );

  $form['styles_scripts']['disable_base_js'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Base Theme JavaScript'),
    '#description' => t('Disabling the base theme JavaScript when using a sub-theme is also recommended for more flexibility over which components get included.<br><strong>If you select this option, uncomment the relevant JS includes in your sub-theme\'s .info file.</strong>'),
    '#default_value' => theme_get_setting('disable_base_js', 'zurb_foundation'),
  );
}
