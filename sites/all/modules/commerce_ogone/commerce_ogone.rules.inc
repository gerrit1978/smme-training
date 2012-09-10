<?php

/**
 * Implements hook_rules_action_info().
 */
function commerce_ogone_rules_action_info() {
  $actions = array();

  $actions['commerce_ogone_make_order_nr_unique'] = array(
    'label' => t('Update order nr to make it unique to Ogone'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order in checkout'),
      ),
    ),
    'group' => t('Commerce Ogone'),
    'callbacks' => array(
      'execute' => 'commerce_ogone_make_order_nr_unique',
    ),
  );

  return $actions;
}

/**
 * Updates the order NR to make it unique for Ogone.
 * Example: Order 45 will become 45.1, 45.2, 45.3, ...
 */
function commerce_ogone_make_order_nr_unique($order) {
  if(strpos($order->order_number, '.') === FALSE) {
    $order->order_number = $order->order_number.'.1';
  } else {
    $parts = explode('.', $order->order_number);
    $order->order_number = $parts[0].'.'.($parts[1]+1);
  }
  commerce_order_save($order);
}

?>