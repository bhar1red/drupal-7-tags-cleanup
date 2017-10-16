# Drupal 7 Tags Cleanup 
One of the problems, user's face is too-many similar tags. Since tags can be created by multiple people, there is a posiblity of two users, creating same tag, with a minor difference. For example, informationTechnology, Information Technology, Information-Technology, information technology,... are all valid tags and mean the same. When a user wants to tag a content, they often gets confused with which tag to use. 

This module, is created as a drush command, scans through such tags, identify which one to keep and deletes other tags. It also updates all content tagged with such similar tags to now tag to real one. For above example, Module would keep Information-Technology and delete all other tags. 

### Installation 
It can be installed as any other drupal modules. 
  * Download source and extract to tags_cleanup folder
  * Copy folder to drupal custom modules directory in drupal.
  * Run ```drush en -y tags_cleanup  ``` to enable module 

### Using 
  * Run ```drush tgc ``` to execute module. 
  * If there is any field, other than field_data_field_tags, that uses tags, add it in tags_cleanup_execute() function. Code is well document, so it wouldn't be much trouble to figure out where to add. 


### Logic

  1. Get data from taxonomy_term_data of type = tags, group by names(Stripped of spaces, special characters, cases) and having count>1
  2. For each row,
  3. Get Duplicate tags to be replaced	
     1. Get list of simmilar names and their tids (check using stipped name)
     2. Sort Array Based on Priority / Preference.
     3. Get list of tids (in sorted order ) into an array() - $z_tids
  4. Update Tags
     1. Update field_data_field_tags. Replace all tid in field_data_field_tags from $z_tids with $z_tids[0]
  5. Clean up duplicate tags from taxonomy_term_data
