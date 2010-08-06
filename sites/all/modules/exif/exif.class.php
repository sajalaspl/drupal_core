<?php
//$Id:

/**
 *
 * @author Raphael Sch�r
 * This is a helper class to handle the whole data processing of exif
 *
 */
Class Exif {
  static private $instance = NULL;

  /**
   * We are implementing a singleton pattern
   */
  private function __construct() {
  }

  public function getInstance() {
    if(is_null(self::$instance)) {
      self::$instance = new self;
    }
    return self::$instance;
  }

  /**
   * Going through all the fields that have been created for a given node type
   * and try to figure out which match the naming convention -> so that we know
   * which exif information we have to read
   *
   * Naming convention are: field_exif_xxx (xxx would be the name of the exif
   * tag to read
   *
   * @param $arCckFields array of CCK fields
   * @return array a list of exif tags to read for this image
   */
  public function getExifFields($arCckFields=array()) {
    $arSections = array('exif', 'file', 'computed', 'ifd0', 'gps', 'winxp', 'iptc');
    $arExif = array();

    foreach ($arCckFields as $field) {
      $ar = explode("_", $field['field_name']);
      if ($ar[0] == 'field' && isset($ar[1]) && in_array($ar[1], $arSections)) {
        unset($ar[0]);
        $section = $ar[1];
        unset($ar[1]);
        $arExif[] = array('section'=>$section, 'tag'=>implode("_", $ar));
      }
    }
    return $arExif;
  }

  /**
   * Read the Information from a picture according to the fields specified in CCK
   * @param $file
   * @param $arTagNames
   * @return array
   */
  public function readExifTags($file, $arTagNames=array()) {
    if (!file_exists($file)) {
      return array();
    }

    $ar_supported_types = array('jpg', 'jpeg');
    if (!in_array($this->getFileType($file), $ar_supported_types)) {
      return array();
    }
    $exif = exif_read_data($file, 0);
    $arSmallExif = array();
    foreach ((array)$exif as $key => $value) {
      $arSmallExif[strtolower($key)] = $value;
    }
    $info = array();

    foreach ($arTagNames as $tagName) {
      if ($tagName['section'] != 'iptc' && !empty($arSmallExif[$tagName['tag']])) {
        $info[$tagName['section'] .'_'. $tagName['tag']] = $arSmallExif[$tagName['tag']];
      }
    }
    return $info;
  }

  private function getFileType($file) {
    $ar = explode('.', $file);
    $ending = $ar[count($ar)-1];
    return $ending;
  }

  public function readIPTCTags($file, $arTagNames=array()) {
    $humanReadableKey = $this->getHumanReadableIPTCkey();
    $size = GetImageSize ($file, $infoImage);
    $iptc = empty($infoImage["APP13"]) ? array() : iptcparse($infoImage["APP13"]);
    $arSmallIPTC = array();
    if (is_array($iptc)) {
      foreach($iptc as $key => $value)
      {
        $resultTag = "";
        foreach($value as $innerkey => $innervalue)
        {
          if( ($innerkey+1) != count($value) ) {
             $resultTag .= $innervalue . ", ";     
          }
          else {
            $resultTag .= $innervalue;
          }
        }
        $arSmallIPTC[$humanReadableKey[$key]] = $resultTag;
      }
    }
    $info = array();
    foreach ($arTagNames as $tagName) {
      if ($tagName['section'] == "iptc") {
        $info[$tagName['section'] .'_'. $tagName['tag']] = $arSmallIPTC[$tagName['tag']];
      }
    }
    return $info;
  }

  /**
   * Just some little helper function to get the iptc fields
   * @return array
   *
   */
  public function getHumanReadableIPTCkey() {
    return array(
      "2#202" => "object_data_preview_data",
      "2#201" => "object_data_preview_file_format_version",
      "2#200" => "object_data_preview_file_format",
      "2#154" => "audio_outcue",
      "2#153" => "audio_duration",
      "2#152" => "audio_sampling_resolution",
      "2#151" => "audio_sampling_rate",
      "2#150" => "audio_type",
      "2#135" => "language_identifier",
      "2#131" => "image_orientation",
      "2#130" => "image_type",
      "2#125" => "rasterized_caption",    
      "2#122" => "writer",
      "2#120" => "caption",
      "2#118" => "contact",
      "2#116" => "copyright_notice",
      "2#115" => "source",
      "2#110" => "credit",
      "2#105" => "headline",
      "2#103" => "original_transmission_reference",
      "2#101" => "country_name",
      "2#100" => "country_code",
      "2#095" => "state",
      "2#092" => "sublocation",
      "2#090" => "city",
      "2#085" => "by_line_title",
      "2#080" => "by_line",
      "2#075" => "object_cycle",
      "2#070" => "program_version",
      "2#065" => "originating_program",
      "2#063" => "digital_creation_time",
      "2#062" => "digital_creation_date",   
      "2#060" => "creation_time",
      "2#055" => "creation_date",
      "2#050" => "reference_number",
      "2#047" => "reference_date",
      "2#045" => "reference_service",
      "2#042" => "action_advised",
      "2#040" => "special_instruction",
      "2#038" => "expiration_time",
      "2#037" => "expiration_date",
      "2#035" => "release_time",
      "2#030" => "release_date",
      "2#027" => "content_location_name",
      "2#026" => "content_location_code",
      "2#025" => "keywords",
      "2#022" => "fixture_identifier",
      "2#020" => "supplemental_category", 
      "2#015" => "category",
      "2#010" => "subject_reference", 
      "2#010" => "urgency",
      "2#008" => "editorial_update",
      "2#007" => "edit_status",
      "2#005" => "object_name",
      "2#004" => "object_attribute_reference",
      "2#003" => "object_type_reference",
      "2#000" => "record_version"
      );
  }
}