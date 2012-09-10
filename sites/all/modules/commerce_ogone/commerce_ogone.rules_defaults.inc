<?php

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_ogone_default_rules_configuration() {
  
  // Init rules
  $rules = array();
  
  // Add a reaction rule to update the order nr on transaction insert/update.
  $rule = rules_reaction_rule();

  $rule->label = t('Update order nr to make it unique to Ogone');
  $rule->active = TRUE;

  $rule
    ->event('commerce_payment_transaction_insert')
    ->event('commerce_payment_transaction_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-payment-transaction:payment-method', 
      'value' => 'ogone',
    ))      
    ->condition('data_is', array(
      'data:select' => 'commerce-payment-transaction:status', 
      'value' => 'failure',
    ))
    ->action('commerce_ogone_make_order_nr_unique', array(
      'commerce_order:select' => 'commerce-payment-transaction:order'
    ));

  $rules['commerce_ogone_make_order_nr_unique'] = $rule;

  return $rules;
}