<?php
/**
 * Displays page navigation for any list that has pagination turned on
 *
 * @copyright 2007-2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param ZendDbResultIterator $this->list
 */
$pages = $this->list->getPaginator()->getPages();
if ($pages->pageCount > 1) {
	$url = new URL($_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI']);
	$url->purgeEmptyParameters();

	echo '<ul class="pageNavigation">';

	// Show the Back button
	if (isset($pages->previous)) {
		$url->page = $pages->first;
		echo "<li><a href=\"$url\" class=\"first\">First</a></li>";

		$url->page = $pages->previous;
		echo "<li><a href=\"$url\" class=\"previous\">Back</a></li>";
	}
	// Show the page number links
	// Show only $maxNumLinks pages at a time
	foreach ($pages->pagesInRange as $page) {
		$url->page = $page;
		$class = ($page == $pages->current) ? 'class="current"' : '';
		echo "<li><a href=\"$url\" $class>$page</a></li>";
	}

	// Show the Next button
	if (isset($pages->next)) {
		$url->page = $pages->next;
		echo "<li><a href=\"$url\" class=\"next\">Next</a></li>";

		$url->page = $pages->last;
		echo "<li><a href=\"$url\" class=\"last\">Last</a></li>";
	}

	echo '</ul>';
}
