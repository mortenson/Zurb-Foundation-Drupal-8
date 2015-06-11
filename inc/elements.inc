<?php
/**
 * Override drupal core messages with Zurb Foundation alert-box messages.
 * Customize the colors within the _settings.scss file.
 *
 * http://foundation.zurb.com/docs/elements.php#panelEx
 */
function zurb_foundation_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'error' => t('Error message'),
    'status' => t('Status message'),
    'warning' => t('Warning message'),
  );

  $status_mapping = array(
    'error' => 'alert',
    'status' => 'success',
    'warning' => 'secondary'
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    if (isset($status_mapping[$type])) {
      $output .= "<div data-alert class=\"alert-box radius $status_mapping[$type]\">\n";
    }
    else {
      $output .= "<div data-alert class=\"alert-box radius\">\n";
    }

    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="visually-hidden">' . $status_heading[$type] . "</h2>\n";
    }

    if (count($messages) > 1) {
      foreach ($messages as $message) {
        $output .= '<p>' . $message . '</p>';
      }
    }
    else {
      $output .= $messages[0];
    }

    if(!theme_get_setting('status_in_reveal', 'zurb_foundation')) {
      $output .= '<a href="#" class="close">&times;</a>';
    }

    $output .= "</div>\n";
  }

  // Enable Modal Status Messages
  if ($output != '' && theme_get_setting('status_in_reveal', 'zurb_foundation')) {
    drupal_add_js("jQuery(document).ready(function() { jQuery('#status-messages').foundation('reveal', 'open');
            });", array('type' => 'inline', 'scope' => 'footer'));
    $output = '<div id="status-messages" class="reveal-modal expand" >'. $output;
    $output .= '<a class="close-reveal-modal">&#215;</a>';
    $output .= "</div>\n";
    $output .= '<div class="reveal-modal-bg"></div>';
  }

  return $output;
}
