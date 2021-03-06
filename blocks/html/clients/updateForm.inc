<?php
/**
 * @copyright 2012 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Client $this->client
 */
$fields = array('url','name','endpoint_id','api_key');
foreach ($fields as $field) {
	$get = 'get'.ucfirst($field);
	$$field = View::escape($this->client->$get());
}
$title = $this->client->getId() ? View::escape('Edit '.$this->client->getName()) : 'Add Client';
?>
<div class="updateClientForm">
	<h2><?php echo $title; ?></h2>
	<p>Clients can specify their own api_key for the endpoint.  The api_key will need to
		have been registered with the Open311 server at the endpoint.
	</p>
	<form method="post" action="<?php echo BASE_URI; ?>/clients/update">
		<fieldset>
			<input name="client_id" type="hidden" value="<?php echo $this->client->getId(); ?>" />
			<table>
				<tr><td><label for="name" class="required">Name</label></td>
					<td><input name="name" id="name" value="<?php echo $name; ?>" /></td>
				</tr>
				<tr><td><label for="url" class="required">URL</label></td>
					<td><input name="url" id="url" value="<?php echo $url; ?>" /></td>
				</tr>
				<tr><td><label for="endpoint_id" class="required">Endpoint</label></td>
					<td><select name="endpoint_id" id="endpoint_id">
						<?php
							$list = new EndpointList();
							$list->find();
							foreach ($list as $endpoint) {
								$selected = $endpoint_id=="{$endpoint->getId()}"
									? 'selected="selected"'
									: '';
								$en = View::escape($endpoint->getName());
								echo "<option value=\"{$endpoint->getId()}\" $selected>$en</option>";
							}
						?>
						</select>
					</td>
				</tr>
				<tr><td><label for="api_key">API Key</label></td>
					<td><input name="api_key" id="api_key" value="<?php echo $api_key; ?>" /></td>
				</tr>
			</table>
			<button type="submit" class="submit">Submit</button>
			<a class="cancel" href="<?php echo BASE_URI; ?>/clients">Cancel</a>
		</fieldset>
	</form>
</div>