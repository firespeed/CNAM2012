xquery version "1.0";
for $x in doc("commande.xml")/boutique/commande
where $x/client="Bernard"
order by $x/numerodecommande descending
return $x/numerodecommande

