<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> id="question" class="question-detail <?php print $classes;?> clearfix">

    <?php if (isset($title_suffix['contextual_links'])): ?>
        <?php print render($title_suffix['contextual_links']); ?>
    <?php endif; ?>
    <?php print $ds_content; ?>
</<?php print $ds_content_wrapper ?>>