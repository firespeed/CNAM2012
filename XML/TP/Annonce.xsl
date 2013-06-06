<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<head>
 <title>Les "Concerts Anacréon"</title>
 </head>
 <body>

 <H1 align="center">Les "Concerts Anacréon" présentent</H1>

 <hr/>

 <br/>

 <H1 align="center">
 Concert le <xsl:value-of select="/Annonce/Date"/>
 </H1>

 <H4 align="center">
 <xsl:value-of select="/Annonce/Lieu"/>
 </H4>

 <H2 align="center">
 Ensemble "<xsl:value-of select="/Annonce/Ensemble"/>"
 </H2>
</xsl:stylesheet>