xquery version "1.0";
for $adherent in doc("adherent.xml")//membre
for $emprunt in doc("emprunt.xml")//contenu
for $livre in doc("livre.xml")//livre

where $adherent/code=$emprunt/code
and $emprunt/isbn=$livre/isbn
 
return  <resultat>
{data($adherent/nom)},{data($adherent/prenom)},  {data($livre/titre)}

</resultat>