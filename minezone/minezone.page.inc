<?php 
/**
 * Please do not commit to this project
 */

function minezone_page() {
	$nid = 50;
	$node = node_load($nid);

	$comentarios = comment_node_page_additions($node);
dsm($comentarios);
	$comentarios = $comentarios["comments"];

	$output = "<h3>$node->title</h3>";
	$output .= "<table class='table table-hover'><thead>
							<th>Autor</th>
							<th>Fecha</th>
							<th>Comentario</th>
						</thead>
						<tbody>";
	for($i=119;$i<124;$i++){
		$output .="<tr><td>".$comentarios[$i]["comment_body"]["#object"]->name."</td>";
		$output .="<td>".format_date($comentarios[$i]["comment_body"]["#object"]->created,'custom','d/m/y')."</td>";
		$output .="<td>".$comentarios[$i]["comment_body"]["#items"][0]['value']."</td></tr>";
	}
	$output .="</tbody></table>";

	return $output;
}

