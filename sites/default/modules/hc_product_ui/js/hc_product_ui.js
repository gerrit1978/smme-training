jQuery(document).ready(function($) {

  var vars = getUrlVars();
	if (typeof(vars["pid"]) === 'number' || typeof(vars["pid"]) === 'string') {
		var selector = "#edit-product-id-" + vars["pid"];
		$(selector).trigger("click");
	} 

});

// Read a page's GET URL variables and return them as an associative array.
function getUrlVars()
{
    var vars = [], hash;
    var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
    for(var i = 0; i < hashes.length; i++)
    {
        hash = hashes[i].split('=');
        vars.push(hash[0]);
        vars[hash[0]] = hash[1];
    }
    return vars;
}
