<?php

$plugin = array(
  'title' => t('Idea Story: Editor\'s Picks'),
  'category' => t('Content panes'),
  'single' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_feature_idea_story_display_top_idea_story_content_type_render
  ($subtype, $conf, $panel_args, $context, $incoming) {
    $top_stories = _gsb_feature_idea_story_display_markup_top_stories();
    return (object) array(
      'title' => 'Top Stories',
      'content' => array(
      '#markup' => $top_stories,
    ),
  );
}
