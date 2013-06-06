xquery version "1.0";
for $adherent in doc("adherent.xml")//membre
for $emprunt in doc("emprunt.xml")//contenu
for $livre in doc("livre.xml")//livre
where 
	$adherent/code=$emprunt/code 
	and $livre/isbn= $emprunt/isbn
return 
	<resultat>
	 {data($adherent/nom)},  
	 {data($emprunt/isbn)},  
	 {data($emprunt/dateemprunt)},  
	 {data($emprunt/dateretour)}, 
	 {data($livre/titre)} 
</resultat>
