<?php

/**
 * Implements template_preprocess_page().
 */
function culturelu_preprocess_page(&$variables) {
  // Assign new navbar attributes.
  $variables['navbar2_attributes'] = new Attribute();
  $variables['navbar2_attributes']->setAttribute('id', 'page--navbar2');
  $variables['navbar2_attributes']->addClass('uk-navbar-container');
  $variables['navbar2_attributes']->setAttribute('uk-navbar', '');
}

/**
 * Implements template_preprocess_region().
 */
function culturelu_preprocess_region(&$variables) {
  // Provide an id attribute to help themers.
  $region = $variables['region'];
  $variables['attributes']['id'] = "region--$region";

  if ($region == 'navbar') {
    $variables['content_left'] = [];
    $variables['content_center'] = [];
    $variables['content_right'] = [];

    foreach ($variables['elements'] as $id => $element) {
      if (is_array($element)) {
        $block = array();

        if (isset($element['#id'])) {
          $block = Block::load($element['#id']);
        }
        elseif (isset($element['#markup'])) {
          $block = Block::load($id);
        }

        if ($block) {
          $navbar_alignment = $block->getThirdPartySetting('uikit_components', 'uikit_navbar_alignment', 'left');

          switch ($navbar_alignment) {
            case 'left':
              $variables['content_left'][$id] = [
                '#markup' => render($element),
              ];
              break;

            case 'center':
              $variables['content_center'][$id] = [
                '#markup' => render($element),
              ];
              break;

            case 'right':
              $variables['content_right'][$id] = [
                '#markup' => render($element),
              ];
              break;
          }
        }
      }
    }
  }
  elseif ($region != 'offcanvas') {
    $region_style = UIkit::getThemeSetting($region . '_style');
    $card_style = UIkit::getThemeSetting($region . '_card_style');
    $region_style = $region_style ? $region_style : 0;
    $region_card_style = $card_style ? $card_style : 0;

    if ($region_style) {
      // Add the region style classes.
      switch ($region_style) {
        case 'card':
          $variables['attributes']['class'][] = 'uk-card';
          $variables['attributes']['class'][] = 'uk-card-body';

          if ($region_card_style) {
            $variables['attributes']['class'][] = "uk-card-$region_card_style";
          }
          break;
      }
    }
  }
}

/**
 * Implements template_preprocess_block().
 */
function culturelu_preprocess_block(&$variables) {
  // Provide an id attribute to help themers.
  if (isset($variables['elements']['#id']) && $id = $variables['elements']['#id']) {
    $id = Html::cleanCssIdentifier($id);
    $variables['attributes']['id'] = $id;

    $base_plugin_id = $variables['base_plugin_id'];
    $system_menu_block = $base_plugin_id == 'system_menu_block';
    if ($block = Block::load($variables['elements']['#id'])) {
      $region = $block->getRegion();

      switch ($region) {
        case 'navbar':
        case 'navbar2':
          if ($system_menu_block) {
            // Define #theme variable for navbar menus.
            $variables['content']['#theme'] = 'menu__navbar';
          }
          break;
      }
    }
  }
}


/**
 * @file
 * Set up variables to be placed within the template (.html.twig) files.
 *
 * The variables set up here apply to both templates (.html.twig) files and
 * functions (theme_HOOK). These are also used for providing
 * @link https://www.drupal.org/node/2354645 Twig Template naming conventions @endlink.
 *
 * @see process.inc
 */

/**
 * Implements template_preprocess_page().
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_page(&$variables) {
}
// */

/**
 * Implements template_preprocess_block().
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_block(&$variables) {
}
// */

/**
 * Implements template_preprocess_breadcrumb().
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_breadcrumb(&$variables) {
}
// */

/**
 * Implements template_preprocess_details().
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_details(&$variables) {
}
// */

/**
 * Implements hook_preprocess_HOOK() for feed-icon.html.twig.
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_feed_icon(&$variables) {
}
// */

/**
 * Implements template_preprocess_form_element().
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_form_element(&$variables) {
}
// */

/**
 * Implements template_preprocess_form_element() for form-element--advanced.html.twig.
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_form_element__advanced(&$variables) {
}
// */

/**
 * Implements template_preprocess_links() for links--dropbutton.html.twig.
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_links__dropbutton(&$variables) {
}
// */

/**
 * Implements template_preprocess_menu_local_action().
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_menu_local_action(&$variables) {
}
// */

/**
 * Implements hook_preprocess_HOOK() for menu-local-tasks.html.twig.
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_menu_local_tasks(&$variables) {
}
// */

/**
 * Implements hook_preprocess_HOOK() for menu--navbar.html.twig
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_menu__navbar(&$variables) {
}
// */

/**
 * Implements hook_preprocess_HOOK() for menu--offcanvas.html.twig
 */
/* -- Delete this line if you want to use this function
function culturelu_preprocess_menu__offcanvas(&$variables) {
}
// */
