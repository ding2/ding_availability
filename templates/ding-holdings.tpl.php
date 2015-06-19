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

$total_text = format_plural($total_count, t('We have 1 copy'), t('We have @count copies'), array('@count' => $total_count));
$reserved_text = format_plural($reserved_count, t('There is 1 user in queue to loan the material'), t('There are @count users in queue to loan the material'));
$acquisition_text = format_plural($in_acquisition, t('(1 material under way)'), t('(@count materials under way)'), array('@count' => $in_acquisition));

if ($in_acquisition > 0) {
  $total_text .= ' ' . $acquisition_text;
}

?>
<p>
  <span><?php print $total_text . "<span class='in-queue'>" . $reserved_text . "</span>"; ?></span>
</p>
<p>
  <?php print $closest_loan; ?>
</p>
<?php print render($holdings); ?>
