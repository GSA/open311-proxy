<?php
/**
 * @copyright 2011 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Endpoiunt $this->endpoint
 * @param GET group
 */
$url = new URL($_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI']);
$url->group = $_GET['group'];
?>
<div class="serviceChooser">
	<h3><a href="<?php echo $url; ?>">
			<?php echo View::escape($_GET['group']); ?>
		</a>
	</h3>
	<ul>
	<?php
		$services = !empty($_GET['group'])
			? $this->endpoint->getGroupServices($_GET['group'])
			: $this->endpoint->getServiceList();
		if ($services) {
			$url = new URL($_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI']);

			foreach ($services as $service) {
				$url->service_code = "{$service->service_code}";
				$service_name = View::escape($service->service_name);
				echo "<li><a href=\"$url\">$service_name</a></li>";
			}
		}
	?>
	</ul>
</div>