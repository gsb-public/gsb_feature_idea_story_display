<?php

$plugin = array(
  'title' => t('Idea Story: Top Stories'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_feature_idea_story_display_top_idea_story_content_type_render
  ($subtype, $conf, $panel_args, $context, $incoming) {
    $stuff = _gsb_feature_idea_story_display_markup_top_stories();
    return (object) array(
      'title' => 'Top Stories',
      'content' => array(
      '#markup' => 'some stuff goes here about top idea stories stuff = ' . $stuff,
    ),
  );
}