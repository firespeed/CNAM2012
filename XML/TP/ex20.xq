xquery version "1.0";
for $x in doc("commande.xml")//commande
return if ($x/@type="papeterie")
then <papeterie>{data($x/client)}</papeterie>
else <autre>{data($x/client)}</autre>