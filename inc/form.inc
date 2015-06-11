<?php

/**
 * Implements hook_form_alter().
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function zurb_foundation_form_alter(&$form, &$form_state, $form_id) {
  // Id's of forms that should be ignored
  // Make this configurable?
  $form_ids = array(
    'node_form',
    'system_site_information_settings',
    'user_profile_form',
    'node_delete_confirm',
  );

  // Only wrap in container for certain form
  if (isset($form['#form_id']) && !in_array($form['#form_id'], $form_ids) && !isset($form['#node_edit_form'])) {
    $form['actions']['#theme_wrappers'] = array();
  }

  // Sexy submit buttons
  if (!empty($form['actions']) && !empty($form['actions']['submit'])) {
    $form['actions']['submit']['#attributes'] = array('class' => array('success', 'button', 'radius'));
  }
}

/**
 * Implementation of theme_form_element_label().
 * @param $variables
 * @return string
 */
function zurb_foundation_form_element_label($variables) {
  if (!empty($variables['element']['#title'])) {
    $variables['element']['#title'] = '<label>' . $variables['element']['#title'] . '</label>';
  }
  if (!empty($variables['element']['#description'])) {
    $variables['element']['#description'] = ' <span data-tooltip class="has-tip tip-top" data-width="250" title="' . strip_tags($variables['element']['#description']) . '">' . t('More information?') . '</span>';
  }
  return theme_form_element_label($variables);
}

/**
 * Returns an array containing ids of any whitelisted drupal elements.
 * The reason is to provide a list of elements we wish to exclude
 * from certain modifications made by the bootstrap theme which
 * break core functionality - e.g. ajax.
 *
 * @return array
 */
function _zurb_foundation_element_whitelist() {
  return array(
    'edit-refresh',
    'edit-pass-pass1',
    'edit-pass-pass2',
    'panels-ipe-cancel',
    'panels-ipe-customize-page',
    'panels-ipe-save',
    'panelizer-save-default',
    'panelizer-ipe-revert',
  );
}

/**
 * Returns HTML for a button form element.
 */
function zurb_foundation_button($variables) {
  $element = $variables['element'];
  $label = check_plain($element['#value']);
  element_set_attributes($element, array('id', 'name', 'value', 'type'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  // Prepare input whitelist - added to ensure ajax functions don't break
  $whitelist = _zurb_foundation_element_whitelist();

  if (isset($element['#id']) && in_array($element['#id'], $whitelist)) {
    return '<input' . drupal_attributes($element['#attributes']) . ">\n"; // This line break adds inherent margin between multiple buttons
  }
  else {
    return '<button' . drupal_attributes($element['#attributes']) . '>'. $label ."</button>\n"; // This line break adds inherent margin between multiple buttons
  }
}
