<?php
/**
 * @file
 * Displays holdings information
 *
 * Available variables:
 *  - $holdings: Html showing detailed holdings information.
 *  - $total_count: Total amount of copies.
 *  - $reserved_count: Amount of reservations.
 */

$total_text = format_plural($total_count, 'We have 1 copy', 'We have @count copies', array('@count' => $total_count));
$reserved_text = format_plural($reserved_count, 'There is 1 user in queue to loan the material', 'There are @count users in queue to loan the material');
$acquisition_text = format_plural($in_acquisition, '(1 material under way)', '(@count materials under way)', array('@count' => $in_acquisition));

if ($in_acquisition > 0) {
  $total_text .= ' ' . $acquisition_text;
}

?>
<p>
  <span><?php print "$total_text. $reserved_text."; ?></span>
</p>
<p>
  <?php print $closest_loan; ?>
</p>
<?php print render($holdings); ?>
