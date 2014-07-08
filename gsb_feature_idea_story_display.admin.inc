<?php

/**
 * Page callback: Admin page to configure Top Idea Stories
 */
function gsb_feature_idea_story_display_config_top_stories() {

  $top_stories = variable_get('gsb_feature_idea_story_display_top_stories', array());

  $form['top_story_one'] = array(
    '#type' => 'entityreference',
    '#title' => 'Top Story 1',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('idea_story'),
    '#era_cardinality' => 1,
    '#default_value' => empty($top_stories) ? '' : $top_stories[0],
    '#process' => array('ajax_process_form', 'entityreference_autocomplete_process_entityreference'),    
  );

  $top_story_two = variable_get('gsb_feature_idea_story_display_top_story_two', '');

  $form['top_story_two'] = array(
    '#type' => 'entityreference',
    '#title' => 'Top Story 2',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('idea_story'),
    '#era_cardinality' => 1,
    '#default_value' => empty($top_stories) ? '' : $top_stories[1],
    '#process' => array('ajax_process_form', 'entityreference_autocomplete_process_entityreference'),
  );

  $top_story_three = variable_get('gsb_feature_idea_story_display_top_story_three', '');

  $form['top_story_three'] = array(
    '#type' => 'entityreference',
    '#title' => 'Top Story 3',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('idea_story'),
    '#era_cardinality' => 1,
    '#default_value' => empty($top_stories) ? '' : $top_stories[2],
    '#process' => array('ajax_process_form', 'entityreference_autocomplete_process_entityreference'),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['#submit'][] = 'gsb_feature_idea_story_display_config_top_stories_submit';

  return $form;

}

/**
 * Custom submit callback for the admin config of top idea stories
 */
function gsb_feature_idea_story_display_config_top_stories_submit(&$form, &$form_state) {

  $top_stories = array();

  $top_stories[0] = $form_state['values']['top_story_one']['entity_id'];
  $top_stories[1] = $form_state['values']['top_story_two']['entity_id'];
  $top_stories[2] = $form_state['values']['top_story_three']['entity_id'];
  
  variable_set('gsb_feature_idea_story_display_top_stories', $top_stories);

  drupal_set_message(t('Your configuration of top stories has been successfully saved.'), 'status', FALSE);
  
}

