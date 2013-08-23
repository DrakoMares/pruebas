<?php 
/**
 * Please do not commit to this project
 */

function minezone_page() {
	$nid = 30;
	$node = node_load($nid);

	dsm($node);
	$output = "<div style='background:#eef;padding:20px 5px 10px 15px;'><h1>Titulo: $node->title </h1>" ;
	$output .= l("Ver nodo","node/$node->nid") ."<br/>";
	$output .=  "Tipo de Contenido: ".ucfirst($node->type) ."<br/>";
	$output .= "Fecha de Creado: ".format_date($node->created, 'custom', 'l d/M/Y')."<br/>";

	$output .= "Cantidad de comentarios: $node->comment_count <br/>";

	if($node->comment_count==0)
		$output .= "Sin Comentarios";
	elseif ($node->comment_count = 1)
		$output .= "Singular Un Comentario";
	elseif ($node->comment_count>1)
		$output .= "$page->comment_count Comentarios";

	$output .= "<br/>Estado del Nodo ";
	if($node->status==1)
		$output .="<span style='color:#0f0;'>Publicado</span>";
	else
		$output .="<span style='color:#f00;'>No Publicado</span>";

	$output .="<br/>Autor: ".l($node->name,"user/$node->uid");


	return $output."</div>";
}
