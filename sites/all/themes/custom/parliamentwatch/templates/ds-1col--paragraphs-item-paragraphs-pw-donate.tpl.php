<?php $node_url=url($path='node/10508', array('absolute' => TRUE)); ?>
<div class="relative entity-paragraphs-item">
  <div class="social-media">
    <a href="https://www.facebook.com/sharer/sharer.php?u=<?php print $node_url; ?>" class="facebook" target="_blank">facebook</a>
    <a href="https://twitter.com/intent/tweet?text=Jetzt für abgeordnetenwatch.de spenden&url=<?php print $node_url; ?>" class="twitter" target="_blank">twitter</a>
  </div>
  <h3><a href="<?php print $node_url; ?>"><?php print render($content['field_pg_content_title']); ?></a></h3>
  <div class="push-bottom-s">
    <?php print render($content['field_pg_content_body']); ?>
  </div>
  <div class="text-center">
    <a href="<?php print $node_url; ?>" class="button">Jetzt spenden</a>
  </div>
</div>