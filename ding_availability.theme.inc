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
    $variables['content']['holdings']['table'] = array(
      '#theme' => 'table',
      '#attributes' => $holdings['holdings']['attributes'],
      '#header' => $holdings['holdings']['header'],
      '#rows' => $holdings['holdings']['rows'],
    );
  }
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
  /*$variables['content']['availabitity'] = array(
    '#theme' => 'item_list',
    '#items' => array(
      0 => array('data' => ucfirst($availability['status']), 'title' => $availability['status']),
    ),
    '#type' => 'ul',
    '#attributes' => array(
      'class' => array(drupal_html_class('ding_availability_status')),
    ),
  );*/
  $variables['attributes']['title'] = $availability['status'];
  $variables['data'] = t(ucfirst($availability['status']));
  $variables['classes_array'][] = 'ding_availability_status';
}

/**
 * Theme ding_availability_holdings
 */
function theme_ding_availability_status(&$variables) {
  return '<li' . drupal_attributes($variables['attributes']) . '>' . $variables['data'] . "</li>";
}