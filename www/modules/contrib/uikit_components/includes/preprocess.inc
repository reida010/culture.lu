<?php

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

use Drupal\Core\Template\Attribute;
use Drupal\uikit_components\UIkitComponents;
use Drupal\uikit_components\MimeStreamWrapper;

/**
 * Prepares variables for UIkit Accordion templates.
 *
 * Default template: uikit-accordion.html.twig.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #items: An array of items to be displayed in the accordion. Each item
 *       must contain the title and content properties.
 *     - #component_options: An array containing the component options to apply
 *       to the accordion. These must be in the form of "option: value" in order
 *       to work correctly.
 *
 * @see \Drupal\uikit_components\Element\UIkitAccordion
 * @see https://getuikit.com/docs/accordion#component-options
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_accordion(&$variables) {
  $element = $variables['element'];

  // Set the items variable, if items is not empty.
  if (!empty($element['#items'])) {
    $variables['items'] = $element['#items'];
  }

  // Set the attributes variable.
  $variables['attributes'] = $element['#attributes'];
}

/**
 * Prrpares variables for UIkit Alert templates.
 *
 * Default template: uikit-alert.html.twig.
 *
 * @param $variables:
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #message: The message to display in the alert.
 *     - #style: The style of the alert. Possible values:
 *       - primary: Give the message a prominent styling.
 *       - success: Indicates success or a positive message.
 *       - warning: Indicates a message containing a warning.
 *       - danger: Indicates an important or error message.
 *       Defaults to "primary".
 *     - #close_button: Boolean indicating whether to include a close button in
 *       the alert. Defaults to FALSE.
 *
 * @see \Drupal\uikit_components\Element\UIkitAlert
 * @see https://getuikit.com/docs/alert
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_alert(&$variables) {
  $element = $variables['element'];

  // Set the attributes for the alert.
  $variables['attributes'] = $element['#attributes'];

  // Set the properties for the alert.
  $variables['message'] = $element['#message'];
  $variables['style'] = $element['#style'];
  $variables['close_button'] = $element['#close_button'];
}

/**
 * Prepares variables for UIkit Article templates.
 *
 * Default template: uikit-article.html.twig.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #title (optional): The title of the article.
 *     - #meta (optional): The metadata of the article, such as the author and
 *       created date.
 *     - #lead (optional): The leading paragraph of the article.
 *     - #content: The content of the article.
 *
 * @see \Drupal\uikit_components\Element\UIkitArticle
 * @see https://getuikit.com/docs/article
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_article(&$variables) {
  $element = $variables['element'];

  // Set the title, meta, lead and content variables, if they are not empty.
  if (!empty($element['#title'])) {
    $variables['title'] = $element['#title'];
  }
  if (!empty($element['#meta'])) {
    $variables['meta'] = $element['#meta'];
  }
  if (!empty($element['#lead'])) {
    $variables['lead'] = $element['#lead'];
  }
  if (!empty($element['#content'])) {
    $variables['content'] = $element['#content'];
  }

  // Set the attributes for the article outer element.
  $variables['attributes'] = $element['#attributes'];
}

/**
 * Prrpares variables for UIkit Badge templates.
 *
 * Default template: uikit-badge.html.twig.
 *
 * @param $variables:
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #value: The value of the article.
 *
 * @see \Drupal\uikit_components\Element\UIkitBadge
 * @see https://getuikit.com/docs/badge
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_badge(&$variables) {
  $element = $variables['element'];

  // Set the attributes for the badge.
  $variables['attributes'] = $element['#attributes'];

  // Set the value for the badge, if not empty.
  if (!empty($element['#value'])) {
    $variables['value'] = $element['#value'];
  }
}

/**
 * Prepares variables for UIkit Breadcrumb templates.
 *
 * Default template: uikit-breadcrumb.html.twig.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #items: An array of items to be displayed in the breadcrumb. Each item
 *       must contain the text property and can optionally contain the url
 *       property to display the item as a link. Each item can also contain a
 *       disabled property to set the item as disabled using 'disabled' => TRUE.
 *
 * @see \Drupal\uikit_components\Element\UIkitBreadcrumb
 * @see https://getuikit.com/docs/breadcrumb
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_breadcrumb(&$variables) {
  $element = $variables['element'];

  // Set the attributes for the breadcrumb.
  $variables['attributes'] = $element['#attributes'];

  // Set the items property.
  $variables['items'] = [];

  foreach ($element['#items'] as $key => $item) {
    $variables['items'][$key] = $item;
  }
}

/**
 * Prrpares variables for UIkit Button templates.
 *
 * Default template: uikit-button.html.twig.
 *
 * @param $variables:
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #text: The text to display in the button.
 *     - #url: The url to use in the button, if the button should be rendered in
 *       an @code <a> @endcode element. If omitted, the button will be rendered
 *       in a @code <button> @endcode element.
 *     - #style: The style of the button. Possible values:
 *       - default: Default button style.
 *       - primary: Indicates the primary action.
 *       - secondary: Indicates an important action.
 *       - danger: Indicates a dangerous or negative action.
 *       - text: Applies an alternative, typographic style.
 *       - link: Makes a @code <button> @endcode look like an @code <a> @endcode
 *         element.
 *       Defaults to "default".
 *     - #size: The size of the button. Possible values are "small" and "large".
 *     - #full_width: A boolean indicating if the button will take up the full
 *       width of the parent element. Defaults to FALSE.
 *     - #disabled: A boolean indicating whether the button is disabled or not.
 *
 * @see \Drupal\uikit_components\Element\UIkitButton
 * @see https://getuikit.com/docs/button
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_button(&$variables) {
  $element = $variables['element'];

  // Set the attributes for the badge.
  $variables['attributes'] = $element['#attributes'];

  if ($element['#text']) {
    $variables['text'] = $element['#text'];
  }
  if ($element['#url']) {
    $variables['button_type'] = 'a';
  }
  else {
    $variables['button_type'] = 'button';
  }
}

/**
 * Prepares variables for UIkit Card templates.
 *
 * Default template: uikit-card.html.twig.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #content: The content of the article.
 *     - #title (optional): The title of the card.
 *     - #style (optional): The style of the card. Defaults to "default".
 *     - #hover (optional): Add hover effect to card. Defaults to FALSE.
 *     - #size (optional): The padding to apply to the card.
 *     - #badge (optional): The badge to apply to the card.
 *     - #header (optional): The heading to add to the card.
 *     - #footer (optional): The footer to add to the card.
 *     - #media (optional): An associative array containing:
 *       - alignment: Where the media is aligned in the card. Possible values
 *         are top or bottom. Left and right alignment is not currently
 *         available.
 *       - image_url: The URL for the image to display in the card.
 *
 * If #media is set, #header and #footer will be ignored. This prevents the
 * layout from being disrupted when #media is set. Since left and right media
 * layouts are too complex, left and right alignment values are currently
 * unavailable. See the documentation link below for more information.
 *
 * @see \Drupal\uikit_components\Element\UIkitCard
 * @see https://getuikit.com/docs/card
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_card(&$variables) {
  $element = $variables['element'];

  // Set the title, content, badge, header, footer and media variables, if they
  // are not empty.
  if (!empty($element['#title'])) {
    $variables['title'] = $element['#title'];
  }
  if (!empty($element['#content'])) {
    $variables['content'] = $element['#content'];
  }
  if (!empty($element['#badge'])) {
    $variables['badge'] = $element['#badge'];
  }
  if (!empty($element['#header'])) {
    $variables['header'] = $element['#header'];
  }
  if (!empty($element['#footer'])) {
    $variables['footer'] = $element['#footer'];
  }
  if (!empty($element['#media'])) {
    $variables['media'] = $element['#media'];
  }

  // Set the attributes variable.
  $variables['attributes'] = $element['#attributes'];
}

/**
 * Prrpares variables for UIkit Comment templates.
 *
 * Default template: uikit-comment.html.twig.
 *
 * @param $variables:
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #avatar: An assocative array containing:
 *       - style_name: The name of the image style to be applied.
 *       - uri: URI of the source image before styling.
 *       - height: The height of the image.
 *       - width: The width of the image.
 *       - alt: The alternative text for text-based browsers. HTML 4 and XHTML
 *         1.0 always require an alt attribute. The HTML 5 draft allows the alt
 *         attribute to be omitted in some cases. Therefore, this variable
 *         defaults to an empty string, but can be set to NULL for the attribute
 *         to be omitted. Usually, neither omission nor an empty string
 *         satisfies accessibility requirements, so it is strongly encouraged
 *         for code using '#theme' => 'image_style' to pass a meaningful value
 *         for this variable.
 *         - http://www.w3.org/TR/REC-html40/struct/objects.html#h-13.8
 *         - http://www.w3.org/TR/xhtml1/dtds.html
 *         - http://dev.w3.org/html5/spec/Overview.html#alt
 *       - title: The title text is displayed when the image is hovered in some
 *         popular browsers.
 *       - attributes: Associative array of attributes to be placed in the img
 *         tag.
 *     - #title: The title to display in the comment header.
 *     - #meta: An array containing the metadata to display in the comment
 *       header.
 *     - #comment: The content to display for the comment body.
 *
 * @see template_preprocess_image_style()
 * @see \Drupal\uikit_components\Element\UIkitComment
 * @see https://getuikit.com/docs/comment
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_comment(&$variables) {
  $element = $variables['element'];

  // Set the attributes for the comment.
  $variables['attributes'] = $element['#attributes'];

  // Set the avatar, title, metadata and comment variables, if not empty.
  if (!empty($element['#avatar'])) {
    $variables['avatar'] = $element['#avatar'];
  }
  if (!empty($element['#title'])) {
    $variables['title'] = $element['#title'];
  }
  if (!empty($element['#meta'])) {
    $variables['meta'] = $element['#meta'];
  }
  if (!empty($element['#comment'])) {
    $variables['comment'] = $element['#comment'];
  }
}

/**
 * Prepares variables for UIkit Countdown templates.
 *
 * Default template: uikit-countdown.html.twig.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #expire_date: The date when the countdown should expire using the ISO
 *       8601 format, e.g. 2017-12-04T22:00:00+00:00 (UTC time).
 *     - #separators: An associative array to insert a separator between each
 *       number, containing:
 *       - days_hours: The separator to insert between the days and hours.
 *       - hours_minutes: The separator to insert between hours and minutes.
 *       - minutes_seconds: The separator to insert between minutes and seconds.
 *     - #labels: An associative array for labels to display below each number,
 *       containing:
 *       - days: The label to display for days.
 *       - hours: The label to display for hours.
 *       - minutes: The label to display for minutes.
 *       - seconds: The label to display for seconds.
 *
 * @see \Drupal\uikit_components\Element\UIkitCountdown
 * @see https://getuikit.com/docs/countdown
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_countdown(&$variables) {
  $element = $variables['element'];

  // Set the separators and labels.
  $variables['separators'] = $element['#separators'];
  $variables['labels'] = $element['#labels'];

  // Set the attributes for the countdown.
  $variables['attributes'] = $element['#attributes'];
}

/**
 * Prepares variables for UIkit Description List templates.
 *
 * Default template: uikit-description.html.twig.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #items: An array of items to be displayed in the description list. Each
 *       item can be an associative array with the properties "term" and
 *       "description", or be a string if the definition should be displayed
 *       with the previous item's term.
 *     - #divider: A boolean indicating whether to add a horizontal line between
 *       list items. Defaults to FALSE.
 *
 * @see \Drupal\uikit_components\Element\UIkitDescriptionList
 * @see https://getuikit.com/docs/description-list
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_description_list(&$variables) {
  $element = $variables['element'];

  // Set the attributes for the description list.
  $variables['attributes'] = $element['#attributes'];

  // Set the items property.
  $variables['items'] = [];

  foreach ($element['#items'] as $key => $item) {
    $variables['items'][$key] = $item;
  }
}

/**
 * Prrpares variables for UIkit Video templates.
 *
 * Default template: uikit-video.html.twig.
 *
 * @param $variables:
 *   An associative array containing:
 *   - element: An associative array containing:
 *     - #embed_iframe: The embed code to display the video. This should be the
 *       the full embed code from the video's source and contain the
 *       @code <iframe> @endcode element. The various embed options, such as
 *       displaying the video controls, should also be included. If this is set,
 *       do not set the #video_sources property.
 *     - #video_sources: An array of full-qualified URLs to the video sources.
 *       Each source should have a different video extension to provide a
 *       fallback source for browser compatibility. If only one source is
 *       provided and the browser does not support the video's file extension,
 *       the video will not display. If this is set, do not set the
 *       #embed_iframe property.
 *     - #display_controls: A boolean indicating whether to display the controls
 *       when the #video_sources property is set. This is ignored if the
 *       #embed_iframe property is set.
 *     - #component_options: An array containing the component options to apply
 *       to the video. These must be in the form of "option: value" in order to
 *       work correctly.
 *
 * @see \Drupal\uikit_components\Element\UIkitVideo
 * @see https://getuikit.com/docs/utility#video
 *
 * @ingroup uikit_components_theme_render
 */
function template_preprocess_uikit_video(&$variables) {
  $element = $variables['element'];
  $variables['embed_iframe'] = $element['#embed_iframe'];

  // Set the attributes for the video.
  $variables['attributes'] = $element['#attributes'];

  // Set the type of content to display for the video.
  if (!empty($element['#embed_iframe'])) {
    // Create a new DomDocument so we can extract the attributes from the
    // user-defined embed code.
    $dom = new DOMDocument();
    $dom->loadHTML($element['#embed_iframe']);
    $iframe = $dom->getElementsByTagName('iframe')->item(0);

    if ($iframe->hasAttributes()) {
      foreach ($iframe->attributes as $attribute) {
        // Add each attribute to the attributes variable.
        $name = $attribute->nodeName;
        $value = $attribute->nodeValue;
        $variables['attributes']->setAttribute($name, $value);
      }
    }
  }
  elseif (!empty($element['#video_sources'])) {
    // Multiple sources are in an array so the user-defined sources can have a
    // fallback video extension for better user experience.
    foreach ($element['#video_sources'] as $source) {
      // Set the src attribute for the video.
      $attributes = new Attribute();
      $attributes->setAttribute('src', $source);

      // Use the mime stream wrapper class to retrieve the mime type for the
      // source.
      $wrapper = new MimeStreamWrapper();
      $wrapper->setPath($source);
      $file_info = new finfo(FILEINFO_MIME);
      $mime_type = $file_info->file($wrapper->getStreamPath(), FILEINFO_MIME_TYPE, $wrapper->getContext());

      // Set the type attribute to use the mime type for the source.
      $attributes->setAttribute('type', $mime_type);

      // Set the source's attributes variable.
      $variables['sources'][] = ['attributes' => $attributes];
    }
  }
}

/**
 * Implements template_preprocess_HOOK() for menu--uikit-list.html.twig.
 */
function template_preprocess_menu__uikit_list(&$variables) {
  $menu_name = $variables['menu_name'];

  $menu_style = UIkitComponents::getMenuStyle($menu_name);
  $large_list = UIkitComponents::getLargeList($menu_name);
  $nav_width_classes = UIkitComponents::getNavWidthClasses($menu_name);

  $attributes = new Attribute();
  $wrapper_attributes = new Attribute();

  $attributes->addClass('uk-list');

  if ($menu_style && $menu_style != 'uk-list') {
    $attributes->addClass($menu_style);
  }

  if ($large_list) {
    $attributes->addClass('uk-list-large');
  }

  if ($nav_width_classes) {
    $classes = explode(' ', $nav_width_classes);

    foreach ($classes as $class) {
      $wrapper_attributes->addClass($class);
    }
  }

  $variables['attributes'] = $attributes;
  $variables['wrapper_attributes'] = $wrapper_attributes;
}

/**
 * Implements template_preprocess_HOOK() for menu--uikit-nav.html.twig.
 */
function template_preprocess_menu__uikit_nav(&$variables) {
  $menu_name = $variables['menu_name'];

  $menu_style = UIkitComponents::getMenuStyle($menu_name);
  $nav_style_modifier = UIkitComponents::getNavStyleModifier($menu_name);
  $nav_center = UIkitComponents::getNavCenterModifier($menu_name);
  $nav_width_classes = UIkitComponents::getNavWidthClasses($menu_name);

  $attributes = new Attribute();
  $wrapper_attributes = new Attribute();

  if ($menu_style) {
    $attributes->addClass('uk-nav');

    if ($nav_style_modifier) {
      $attributes->addClass($nav_style_modifier);
    }

    if ($nav_center) {
      $attributes->addClass('uk-nav-center');
    }

    foreach ($variables['items'] as $index => $item) {
      if ($item['below']) {
        $variables['items'][$index]['attributes']->addClass('uk-parent');
      }
    }
  }

  if ($nav_width_classes) {
    $classes = explode(' ', $nav_width_classes);

    foreach ($classes as $class) {
      $wrapper_attributes->addClass($class);
    }
  }

  $variables['attributes'] = $attributes;
  $variables['wrapper_attributes'] = $wrapper_attributes;
}

/**
 * Implements template_preprocess_HOOK() for menu--uikit-subnav.html.twig.
 */
function template_preprocess_menu__uikit_subnav(&$variables) {
  $menu_name = $variables['menu_name'];

  $menu_style = UIkitComponents::getMenuStyle($menu_name);
  $nav_width_classes = UIkitComponents::getNavWidthClasses($menu_name);

  $attributes = new Attribute();
  $wrapper_attributes = new Attribute();

  if ($menu_style) {
    $attributes->addClass('uk-subnav');

    if ($menu_style != 'uk-subnav') {
      $attributes->addClass($menu_style);
    }
  }

  if ($nav_width_classes) {
    $classes = explode(' ', $nav_width_classes);

    foreach ($classes as $class) {
      $wrapper_attributes->addClass($class);
    }
  }

  $variables['attributes'] = $attributes;
  $variables['wrapper_attributes'] = $wrapper_attributes;
}
