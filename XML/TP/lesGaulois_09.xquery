xquery version "1.0";
<html>
<body>
    <h2>Asterix</h2>
 {
for $x in doc("lesgaulois.xml")//villageois
where $x/NOM = 'Asterix'
return 
<div>
	<div style="float:left">
		<img src="imagesGaulois/{$x/IMAGE/text()}"  />
	</div>
	<div style="float:left;font-family:verdana;font-weigth:bold;font-size:12px;margin-left:10px;" >
		Nom : {$x/NOM/text()}
	<br />
		ADRESSE : {$x/ADRESSE/text()}
	<br />
		Specialite : {$x/NOM_SPECIALITE/text()}
	</div>
</div>
}

</body>
</html>