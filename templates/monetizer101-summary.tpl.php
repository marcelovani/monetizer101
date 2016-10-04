<div class="field-monetizer101-summary">
  <?php if (!empty($table['#items'])): ?>
    <h3>Best Deals</h3>
    <?php print drupal_render($table); ?>
  <?php endif; ?>
  <?php if ($view_all_link): ?>
    <?php print $view_all_link; ?>
  <?php endif; ?>
</div>
