<?xml version="1.0" encoding="ISO-8859-1"?> <xsl:stylesheet version = '1.0' 	xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>	<xsl:template match="AAA">		<html>			<head>				<title>XSL</title>			</head>			<body>				<xsl:apply-templates />			</body>		</html>	</xsl:template><xsl:template match="//BBB[@*]">	<div style="color:red">		<xsl:value-of select="name()"/>	</div></xsl:template></xsl:stylesheet>