<?php


/**
 * Preprocess ding_availability_holdings
 */
function template_preprocess_ding_availability_holdings(&$variables) {
  $variables['content'] = array();
  
  $holdings = $variables['holdings'];
  $variables['content']['title'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>' . t('Position') . '</h2>',
  );
  $items = array();
  if(isset($holdings['location'])) {
    foreach($holdings['location']['holdings'] as $count => $location) {
      $items[] = join(' → ', $location);
    }
    $variables['content']['location'] = array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#title' => '',
      '#type' => 'ul',
      '#attributes' => array(
        'class' => array(drupal_html_class('ding_availability_location')),
      ),
    );
  }
  if(isset($holdings['holdings'])) {
    $variables['content']['holdings'] = array(
      '#type' => 'fieldset', 
      '#title' => t('View all holdings'),
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      '#attached' => array(
        'js' => array(
          'misc/form.js',
          'misc/collapse.js',
        ),
      ),
      '#attributes' => array(
        'class' => array('collapsible', 'collapsed'),
      ),
    );
    $row = array();
    $row['data']['Library'] = t('Reservations');
    $row['data']['Copies'] = $variables['holdings']['reserved_count'];
    $row['data']['Home'] = '';
    $row['data']['Reference'] = '';
    $row['data']['Checked_out'] = '';
    $row['class'] = array(drupal_html_class('availability_holdings_last_row'));
    $holdings['holdings']['rows'][] = $row;
    
    $variables['content']['holdings']['table'] = array(
      '#theme' => 'table',
      '#attributes' => $holdings['holdings']['attributes'],
      '#header' => $holdings['holdings']['header'],
      '#rows' => $holdings['holdings']['rows'],
    );
  }
  $variables['classes'] = '';
  $variables['classes_array'] = array();
  $variables['classes_array'][] = 'ding_availability_holdings';
}

/**
 * Theme ding_availability_holdings
 */
function theme_ding_availability_holdings(&$variables) {
  return '<div class="' . $variables['classes'] . '">' . render($variables['content']) . '</div>';
}

/**
 * Preprocess ding_availability_status
 */
function template_preprocess_ding_availability_status(&$variables) {
  $availability = $variables['availability'];
  $variables['attributes']['title'] = $availability['status'];
  if($availability['available']) {
    $variables['attributes']['class'][] = 'available';
  }
  if($availability['reservable']) {
    $variables['attributes']['class'][] = 'reservable';
  }
  if($availability['is_internet']) {
    $variables['attributes']['class'][] = drupal_html_class('is_internet');
  }
  if($availability['is_periodical']) {
    $variables['attributes']['class'][] = drupal_html_class('is_periodical');
  }
  $variables['data'] = t(ucfirst($availability['status']));
  $variables['classes_array'][] = 'ding_availability_status';
}

/**
 * Theme ding_availability_holdings
 */
function theme_ding_availability_status(&$variables) {
  return '<li' . drupal_attributes($variables['attributes']) . '>' . $variables['data'] . "</li>";
}