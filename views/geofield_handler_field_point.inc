<?php
// $Id$

/**
 * A field that displays fields.
 */
class geofield_handler_field_point extends views_handler_field_field {
  function render($values) {
    if (isset($values->_field_data[$this->field_alias])) {
      // Prepare arguments for rendering based on the objects cached in the
      // pre-render phase and the display options for this field.
      $entity_type = $values->_field_data[$this->field_alias]['entity_type'];
      $object = $values->_field_data[$this->field_alias]['object'];

      foreach ($object as $a) {
        if (is_array($a)) {
          foreach ($a as $b) {
            return 'POINT( ' . $b[0]['lat'] . ' ' . $b[0]['lon'] . ')';
          }
        }
      }
    }
    else {
      return '';
    }
  }
}
