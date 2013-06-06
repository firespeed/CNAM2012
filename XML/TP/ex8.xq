xquery version "1.0";
"Le client de la commande 3 est : ",
doc("commande.xml")//commande[5]/client/text()