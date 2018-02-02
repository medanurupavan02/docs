Action()
{

	web_set_sockets_option("SSL_VERSION", "2&3");
	
	

	web_reg_find("Text=AgentLink", LAST);
	
	

	web_url("qa-agentlink.secura.net", 
		"URL=https://qa-agentlink.secura.net/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);


	web_reg_find("Text=AgentLink", LAST);

	web_add_header("UA-CPU", "AMD64");
	
	

	web_url("favicon.ico", 
		"URL=https://qa-agentlink.secura.net/favicon.ico", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		//"EncType=text/html",
		LAST);

	lr_start_transaction("Authentication");

	web_reg_find("Text=Redirect", LAST);
	
	/*Correlation comment - Do not change!  Original value='843c7e863ad66987236d67763aa37b6f7db4f91d98cfccf7b6259351765839e8' Name ='CSRF_TOKEN' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/DisplayWorkInProgress*",
		LAST);

	web_submit_data("qa-agentlink.secura.net_2", 
		"Action=https://qa-agentlink.secura.net/", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=httpd_username", "Value=agntporttest0+0200681@gmail.com", ENDITEM, 
		"Name=httpd_password", "Value=Portal123*", ENDITEM, 
		LAST);

	

	web_reg_find("Text=AgentLink", LAST);

	web_url("AgentLink", 
		"URL=https://qa-agentlink.secura.net/AgentLink", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/AgentLink/fonts/Gotham/Gotham-Black.otf", ENDITEM, 
		"Url=/AgentLink/fonts/glyphicons-halflings-regular.eot?", ENDITEM, 
		"Url=/AgentLink/fonts/fontawesome-webfont.eot?", ENDITEM, 
		//"Url=https://www.google-analytics.com/analytics.js", ENDITEM, 
		LAST);

	lr_end_transaction("Authentication",LR_AUTO);

	lr_start_transaction("Agency portal");

	web_reg_find("Text=agencyportal", LAST);



	web_url("Agency Portal", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgentLink", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		"Url=assets/fonts/font-awesome/fontawesome-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		"Url=assets/themes/secura/logo.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		"Url=assets/themes/secura/colorbar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		"Url=assets/themes/secura/orangebar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		LAST);

	web_url("cardView.jsp", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/worklist/partials/cardView.jsp", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

/*Correlation comment - Do not change!  Original value='fa1bce0cf515e3340ebba466d999428c66c3e900723dd5c89f7afeed1c341a3f' Name ='CSRF_TOKEN1' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN1",
		"RegExp=CSRF_TOKEN:\\ (.*?)\\\r\\\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		LAST);

	web_url("WorkItemsView",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/worklists/workitems/views/WorkItemsView?CSRF_TOKEN={CSRF_TOKEN}&saved_search_id=-1",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t8.inf",
		"Mode=HTML",
		LAST);

	web_url("messages.tpl.jsp", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/shared/partials/messages.tpl.jsp", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", "XMLHttpRequest");

	web_submit_data("FileUploadServlet", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_url("ACCOUNT_TYPE",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/ACCOUNT_TYPE?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t11.inf",
		"Mode=HTML",
		LAST);

	web_url("TRANSACTION_TYPE",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/TRANSACTION_TYPE?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t12.inf",
		"Mode=HTML",
		LAST);

/*Correlation comment - Do not change!  Original value='ac6d7470a74c636b26732fdbbe217f4d2ee7ee84d9415b200ae014bdb215a5ea' Name ='CSRF_TOKEN11_1' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN11_1",
		"RegExp=CSRF_TOKEN:\\ (.*?)\\\r\\\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		LAST);

	web_url("NewWorkItemLink",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/NewWorkItemLink?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t13.inf",
		"Mode=HTML",
		LAST);

/*Correlation comment - Do not change!  Original value='fca263a57c73e1a72223c8eff273e568bad2a2e5ebf0dd2ba0f7f527189cc08c' Name ='CSRF_TOKEN2' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN2",
		"RegExp=CSRF_TOKEN:\\ (.*?)\\\r\\\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		LAST);

	web_url("worklistAdvancedSearch",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/products/transactions/worklist/pages/worklistAdvancedSearch?CSRF_TOKEN={CSRF_TOKEN1}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t14.inf",
		"Mode=HTML",
		LAST);

	web_url("worklist-addnewcard.tpl.jsp", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/worklist/partials/worklist-addnewcard.tpl.jsp", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("LOB",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/LOB?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t16.inf",
		"Mode=HTML",
		LAST);

	web_url("STATUS",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/STATUS?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t17.inf",
		"Mode=HTML",
		LAST);

	web_url("tabularView.jsp", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/worklist/partials/tabularView.jsp", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("custom%3Acom.agencyport.api.pojo.OperatorsListBuilder%3AdataType%3DDATE%3A5.0.0.0",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/products/optionlistids/custom%3Acom.agencyport.api.pojo.OperatorsListBuilder%3AdataType%3DDATE%3A5.0.0.0?transaction_id=worklist&field_id=operator&page_id=worklistAdvancedSearch&CSRF_TOKEN={CSRF_TOKEN2}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t19.inf",
		"Mode=HTML",
		LAST);

/*Correlation comment - Do not change!  Original value='df6e8bc57501dd380280c5e04d35b18845b20d506b79e3606104ca2457216a2b' Name ='CSRF_TOKEN3' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN3",
		"RegExp=CSRF_TOKEN:\\ (.*?)\\\r\\\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		LAST);

	web_custom_request("WorkItemsView_2",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/worklists/workitems/views/WorkItemsView?CSRF_TOKEN={CSRF_TOKEN1}&saved_search_id=-1",
		"Method=PUT",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t20.inf",
		"Mode=HTML",
		"EncType=application/json",
		"Body={\"csrftokenname\":\"CSRF_TOKEN\",\"csrftoken\":\"{CSRF_TOKEN1}\",\"searchName\":-1,\"listId\":\"WorkItemsView\",\"worklistType\":\"workitems\",\"CSRF_TOKEN\":\"{CSRF_TOKEN1}\",\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/views/WorkItemsView\",\"parameters\":[\"saved_search_id\"]},\"name\":\"WorkItemsView\",\"title\":\"Worklist View\",\"version\":\"5.4.0-0\",\"index\":\"worklist\",\"filters\":[{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/filter_infos/lob?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"lob\",\"title\":\"LOB\",\"filterOptions\":[{\"title\":\"Commercial Auto\",\"value\":\"AUTOB\",\"selected\":false},{\"title\":\"Commercial Package\",\"value\":\"CPKGE\",\"selected\":false},{\"title\":\"Workers' Comp\",\"value\":\"WORK\",\"selected\":false}],\"styleClass\":null,\"format\":null,\"relatedFieldId\":\"lob\",\"type\":\"LOB\",\"isSaveable\":true},{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/filter_infos/status?view_name=W"
		"orkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"status\",\"title\":\"Status\",\"filterOptions\":[{\"title\":\"Closed\",\"value\":\"CLOSED\",\"selected\":false},{\"title\":\"In-Progress\",\"value\":\"INPROGRESS\",\"selected\":false},{\"title\":\"Ineligible / Clearance Approved\",\"value\":\"APPROVEINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Ineligible / Clearance Declined\",\"value\":\"REJECTINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Ineligible / Clearance Referred\",\"value\":\"REFERINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Issued\",\"value\":\"ISSUED\",\"selected\":false},{\"title\":\"Referred to UW\",\"value\":\"REFER\",\"selected\":false},{\"title\":\"SECURA In-Progress\",\"value\":\"SECURAINPROGRESS\",\"selected\":false},{\"title\":\"SECURA Pending\",\"value\":\"SEUCRAINCOMPLETE\",\"selected\":false},{\"title\":\"Submitted for Issuance\",\"value\":\"SUBMITTEDFORISSUANCE\",\"selected\":false},{\"title\":\"UW Approved\",\"value\":\"APPROVE\",\"selected\":false"
		"},{\"title\":\"UW Declined\",\"value\":\"DECLINE\",\"selected\":false}],\"styleClass\":null,\"format\":null,\"relatedFieldId\":\"status\",\"type\":\"STATUS\",\"isSaveable\":true}],\"sortInfo\":{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/sort_info?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"workitem_sort_by\",\"title\":\"Sort By\",\"sortOptions\":[{\"relatedFieldId\":\"entity_name\",\"title\":\"Name\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"quote_number\",\"title\":\"Quote Number\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"lob\",\"title\":\"LOB\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"effective_date\",\"title\":\"Effective\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"status\",\"title\":\"Status\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"premium\",\"title\":\"Prem"
		"ium\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"agency_code\",\"title\":\"Agency Code\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"agency_name\",\"title\":\"Agency Name\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"underwriter_name\",\"title\":\"Underwriter\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"last_update_time\",\"title\":\"Updated\",\"ascending\":false,\"selected\":true,\"isSaveable\":true}]},\"queryInfo\":{\"name\":\"workitem_query_info\",\"title\":\"More Options\",\"queryFields\":[{\"relatedFieldId\":\"quote_number\",\"title\":\"Quote Number\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"quoteNumber\",\"isSaveable\":true},{\"relatedFieldId\":\"effective_date\",\"title\":\"Effective\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"DATE\",\"interactive\":true"
		",\"pageFieldId\":\"effectiveDate\",\"isSaveable\":true},{\"relatedFieldId\":\"agency_code\",\"title\":\"Agency Code\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"agencyCode\",\"isSaveable\":true},{\"relatedFieldId\":\"agency_name\",\"title\":\"Agency Name\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"agencyName\",\"isSaveable\":true},{\"relatedFieldId\":\"underwriter_name\",\"title\":\"Underwriter\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"underwriterName\",\"isSaveable\":true},{\"relatedFieldId\":\"entity_name\",\"title\":\"Name\",\"selected\":false,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"agency_name\",\"title\":\"Agency Name\",\"selected\":false"
		",\"opCode\":{\"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"underwriter_name\",\"title\":\"Underwriter\",\"selected\":false,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"status\",\"title\":\"Status\",\"selected\":true,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"NOT_EQUAL\"},\"operands\":[\"DELETE\"],\"dataType\":\"STATUS\",\"interactive\":false,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"commit_flag\",\"title\":\"Commit Flag\",\"selected\":true,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"EQUALS\"},\"operands\":[\"1\"],\"dataType\":\"INTEGER\",\"interactive\":false,\"pageFieldId\":null,\"isSaveable\":false}],\"transactionId\":\"worklist\",\"pageId\":\"worklistAdvancedSearch\",\"links\":[{\"rel\":"
		"\"self\",\"href\":\"/api/worklists/workitems/query_info?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},{\"rel\":\"operators\",\"href\":\"/api/worklists/workitems/operator_infos\",\"parameters\":[]},{\"rel\":\"dialog-resource\",\"href\":\"/api/products/transactions/worklist/pages/worklistAdvancedSearch\",\"parameters\":[]}]},\"listViews\":[{\"fields\":[{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"ID\",\"id\":\"work_item_id\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"Account Id\",\"id\":\"account_id\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Name\",\"id\":\"entity_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Quote Number\",\"id\":\"quote_number\",\"isDisplayed\":true},{\"type\":\"LOB\",\"styleClass\":null,\"format\":null,\"title\":\"LOB\",\"id\":\"lob\",\"isDisplayed\":true},{\"type\":\"DATE\",\"styleClass\":null,\"format"
		"\":null,\"title\":\"Effective\",\"id\":\"effective_date\",\"isDisplayed\":true},{\"type\":\"STATUS\",\"styleClass\":null,\"format\":null,\"title\":\"Status\",\"id\":\"status\",\"isDisplayed\":true},{\"type\":\"DECIMAL\",\"styleClass\":null,\"format\":\"currency: ' '\",\"title\":\"Premium\",\"id\":\"premium\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Code\",\"id\":\"agency_code\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Name\",\"id\":\"agency_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter ID\",\"id\":\"underwriter_id\",\"isDisplayed\":false},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter\",\"id\":\"underwriter_name\",\"isDisplayed\":true},{\"type\":\"TIME\",\"styleClass\":null,\"format\":null,\"title\":\"Updated\",\"id\":\"last_update_time\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":nul"
		"l,\"format\":null,\"title\":\"Transaction Type\",\"id\":\"transaction_type\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":\"percentage\",\"title\":\"Complete %\",\"id\":\"complete_percent\",\"isDisplayed\":false}],\"type\":\"CARD\",\"viewPortSize\":20,\"startRowNumber\":0,\"selected\":false,\"fetchSize\":20},{\"fields\":[{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"ID\",\"id\":\"work_item_id\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"Account Id\",\"id\":\"account_id\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Name\",\"id\":\"entity_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Quote Number\",\"id\":\"quote_number\",\"isDisplayed\":true},{\"type\":\"LOB\",\"styleClass\":null,\"format\":null,\"title\":\"LOB\",\"id\":\"lob\",\"isDisplayed\":true},{\"type\":\"DATE\",\"styleClass\":null,\"format\":null,\"ti"
		"tle\":\"Effective\",\"id\":\"effective_date\",\"isDisplayed\":true},{\"type\":\"STATUS\",\"styleClass\":null,\"format\":null,\"title\":\"Status\",\"id\":\"status\",\"isDisplayed\":true},{\"type\":\"DECIMAL\",\"styleClass\":null,\"format\":\"currency: ' '\",\"title\":\"Premium\",\"id\":\"premium\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Code\",\"id\":\"agency_code\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Name\",\"id\":\"agency_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter ID\",\"id\":\"underwriter_id\",\"isDisplayed\":false},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter\",\"id\":\"underwriter_name\",\"isDisplayed\":true},{\"type\":\"TIME\",\"styleClass\":null,\"format\":null,\"title\":\"Updated\",\"id\":\"last_update_time\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\""
		":null,\"title\":\"Transaction Type\",\"id\":\"transaction_type\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":\"percentage\",\"title\":\"Complete %\",\"id\":\"complete_percent\",\"isDisplayed\":false}],\"type\":\"TABULAR\",\"viewPortSize\":40,\"startRowNumber\":0,\"selected\":true,\"fetchSize\":40}],\"savedSearchInfo\":{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/saved_searches?view_name=WorkItemsView\",\"parameters\":[\"saved_search_id\",\"view_name\"]},\"savedSearches\":[],\"currentSearch\":{\"id\":-1,\"name\":null,\"isActive\":true}},\"lookupLinks\":[{\"rel\":\"lookups.basic.STATUS\",\"href\":\"/api/lookups/basic/STATUS\",\"parameters\":null},{\"rel\":\"lookups.basic.ACCOUNT_TYPE\",\"href\":\"/api/lookups/basic/ACCOUNT_TYPE\",\"parameters\":null},{\"rel\":\"lookups.basic.TRANSACTION_TYPE\",\"href\":\"/api/lookups/basic/TRANSACTION_TYPE\",\"parameters\":null},{\"rel\":\"lookups.basic.LOB\",\"href\":\"/api/lookups/basic/LOB\",\"parameters\":null},{\"rel\":"
		"\"lookups.basic.NewWorkItemLink\",\"href\":\"/api/lookups/basic/NewWorkItemLink\",\"parameters\":[\"worklistType\"]}],\"isSaveable\":true}",
		LAST);

	web_url("NewWorkItemLink_2",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/NewWorkItemLink?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t21.inf",
		"Mode=HTML",
		LAST);

	web_custom_request("WorkItemsView_3",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/worklists/workitems/views/WorkItemsView?CSRF_TOKEN={CSRF_TOKEN3}&saved_search_id=",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t22.inf",
		"Mode=HTML",
		"EncType=application/json",
		"Body={\"csrftokenname\":\"CSRF_TOKEN\",\"csrftoken\":\"{CSRF_TOKEN3}\",\"listId\":\"WorkItemsView\",\"worklistType\":\"workitems\",\"CSRF_TOKEN\":\"{CSRF_TOKEN1}\",\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/views/WorkItemsView\",\"parameters\":[\"saved_search_id\"]},\"name\":\"WorkItemsView\",\"title\":\"Worklist View\",\"version\":\"5.4.0-0\",\"index\":\"worklist\",\"filters\":[{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/filter_infos/lob?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"lob\",\"title\":\"LOB\",\"filterOptions\":[{\"title\":\"Commercial Auto\",\"value\":\"AUTOB\",\"selected\":false},{\"title\":\"Commercial Package\",\"value\":\"CPKGE\",\"selected\":false},{\"title\":\"Workers' Comp\",\"value\":\"WORK\",\"selected\":false}],\"styleClass\":null,\"format\":null,\"relatedFieldId\":\"lob\",\"type\":\"LOB\",\"isSaveable\":true,\"status\":{\"isopen\":false}},{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/filter_infos/status"
		"?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"status\",\"title\":\"Status\",\"filterOptions\":[{\"title\":\"Closed\",\"value\":\"CLOSED\",\"selected\":false},{\"title\":\"In-Progress\",\"value\":\"INPROGRESS\",\"selected\":false},{\"title\":\"Ineligible / Clearance Approved\",\"value\":\"APPROVEINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Ineligible / Clearance Declined\",\"value\":\"REJECTINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Ineligible / Clearance Referred\",\"value\":\"REFERINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Issued\",\"value\":\"ISSUED\",\"selected\":false},{\"title\":\"Referred to UW\",\"value\":\"REFER\",\"selected\":false},{\"title\":\"SECURA In-Progress\",\"value\":\"SECURAINPROGRESS\",\"selected\":false},{\"title\":\"SECURA Pending\",\"value\":\"SEUCRAINCOMPLETE\",\"selected\":false},{\"title\":\"Submitted for Issuance\",\"value\":\"SUBMITTEDFORISSUANCE\",\"selected\":false},{\"title\":\"UW Approved\",\"value\":\"APPROVE\",\"sele"
		"cted\":false},{\"title\":\"UW Declined\",\"value\":\"DECLINE\",\"selected\":false}],\"styleClass\":null,\"format\":null,\"relatedFieldId\":\"status\",\"type\":\"STATUS\",\"isSaveable\":true,\"status\":{\"isopen\":false}}],\"sortInfo\":{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/sort_info?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"workitem_sort_by\",\"title\":\"Sort By\",\"sortOptions\":[{\"relatedFieldId\":\"entity_name\",\"title\":\"Name\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"quote_number\",\"title\":\"Quote Number\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"lob\",\"title\":\"LOB\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"effective_date\",\"title\":\"Effective\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"status\",\"title\":\"Status\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"rel"
		"atedFieldId\":\"premium\",\"title\":\"Premium\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"agency_code\",\"title\":\"Agency Code\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"agency_name\",\"title\":\"Agency Name\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"underwriter_name\",\"title\":\"Underwriter\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"last_update_time\",\"title\":\"Updated\",\"ascending\":false,\"selected\":true,\"isSaveable\":true}]},\"queryInfo\":{\"name\":\"workitem_query_info\",\"title\":\"More Options\",\"queryFields\":[{\"relatedFieldId\":\"quote_number\",\"title\":\"Quote Number\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"quoteNumber\",\"isSaveable\":true},{\"relatedFieldId\":\"effective_date\",\"title\":\"Effective\",\"selected\":false,\"opCode\":null,\"operands\":[],"
		"\"dataType\":\"DATE\",\"interactive\":true,\"pageFieldId\":\"effectiveDate\",\"isSaveable\":true},{\"relatedFieldId\":\"agency_code\",\"title\":\"Agency Code\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"agencyCode\",\"isSaveable\":true},{\"relatedFieldId\":\"agency_name\",\"title\":\"Agency Name\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"agencyName\",\"isSaveable\":true},{\"relatedFieldId\":\"underwriter_name\",\"title\":\"Underwriter\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"underwriterName\",\"isSaveable\":true},{\"relatedFieldId\":\"entity_name\",\"title\":\"Name\",\"selected\":false,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"agency_name\",\""
		"title\":\"Agency Name\",\"selected\":false,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"underwriter_name\",\"title\":\"Underwriter\",\"selected\":false,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"status\",\"title\":\"Status\",\"selected\":true,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"NOT_EQUAL\"},\"operands\":[\"DELETE\"],\"dataType\":\"STATUS\",\"interactive\":false,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"commit_flag\",\"title\":\"Commit Flag\",\"selected\":true,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"EQUALS\"},\"operands\":[\"1\"],\"dataType\":\"INTEGER\",\"interactive\":false,\"pageFieldId\":null,\"isSaveable\":false}],\"transactionId\":\"worklist\",\"pageId\":\"wor"
		"klistAdvancedSearch\",\"links\":[{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/query_info?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},{\"rel\":\"operators\",\"href\":\"/api/worklists/workitems/operator_infos\",\"parameters\":[]},{\"rel\":\"dialog-resource\",\"href\":\"/api/products/transactions/worklist/pages/worklistAdvancedSearch\",\"parameters\":[]}],\"pages\":[{\"name\":\"worklistAdvancedSearch\",\"title\":\"More Options\",\"type\":\"dataEntry\",\"styleClass\":\"\",\"dataSource\":null,\"hasHotFields\":false,\"slowLoader\":false,\"validateTransactionOnDisplay\":false,\"supportsIPDTRDynamicContent\":false,\"sections\":[{\"name\":\"worklistAdvancedSearch\",\"legend\":\"More Options\",\"type\":\"fieldset\",\"styleClass\":\"\",\"interestLevel\":2,\"fields\":[{\"name\":\"quoteNumber\",\"type\":\"text\",\"styleClass\":\"\",\"interestLevel\":2,\"isHot\":false,\"label\":\"Quote Number\",\"readOnly\":false,\"required\":false,\"defaultValue\":\"\",\"length\":-1,\"maxLength\":9,\"minLength\":-"
		"1,\"size\":9},{\"name\":\"operator\",\"type\":\"selectlist\",\"styleClass\":\"\",\"interestLevel\":2,\"isHot\":false,\"label\":\"Operator\",\"readOnly\":false,\"required\":false,\"defaultValue\":\"LESS_THAN\",\"optionLists\":[{\"isStatic\":false,\"link\":{\"rel\":\"self\",\"href\":\"/api/products/optionlistids/custom%3Acom.agencyport.api.pojo.OperatorsListBuilder%3AdataType%3DDATE%3A5.0.0.0?transaction_id=worklist&field_id=operator&page_id=worklistAdvancedSearch\",\"parameters\":[\"work_item_id\"]}}],\"options\":[{\"value\":\"EQUALS\",\"displayText\":\"on\"},{\"value\":\"GREATER_THAN\",\"displayText\":\"after\"},{\"value\":\"NOT_EQUAL\",\"displayText\":\"not on\"},{\"value\":\"BETWEEN\",\"displayText\":\"between\"},{\"value\":\"LESS_THAN\",\"displayText\":\"before\"}],\"selectedOption\":\"LESS_THAN\"},{\"name\":\"effectiveDate\",\"type\":\"date\",\"styleClass\":\"\",\"interestLevel\":2,\"isHot\":false,\"label\":\"Effective\",\"readOnly\":false,\"required\":false,\"defaultValue\":\"\",\"length\":-1,\"maxLeng"
		"th\":10,\"minLength\":-1,\"size\":10,\"selectedOperator\":\"LESS_THAN\"},{\"name\":\"agencyCode\",\"type\":\"text\",\"styleClass\":\"\",\"interestLevel\":2,\"isHot\":false,\"label\":\"Agency Code\",\"readOnly\":false,\"required\":false,\"defaultValue\":\"\",\"length\":-1,\"maxLength\":15,\"minLength\":-1,\"size\":15},{\"name\":\"agencyName\",\"type\":\"text\",\"styleClass\":\"\",\"interestLevel\":2,\"isHot\":false,\"label\":\"Agency Name\",\"readOnly\":false,\"required\":false,\"defaultValue\":\"\",\"length\":-1,\"maxLength\":40,\"minLength\":-1,\"size\":15},{\"name\":\"underwriterName\",\"type\":\"text\",\"styleClass\":\"\",\"interestLevel\":2,\"isHot\":false,\"label\":\"Underwriter\",\"readOnly\":false,\"required\":false,\"defaultValue\":\"\",\"length\":-1,\"maxLength\":128,\"minLength\":-1,\"size\":15}]}]}]},\"listViews\":[{\"fields\":[{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"ID\",\"id\":\"work_item_id\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"forma"
		"t\":null,\"title\":\"Account Id\",\"id\":\"account_id\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Name\",\"id\":\"entity_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Quote Number\",\"id\":\"quote_number\",\"isDisplayed\":true},{\"type\":\"LOB\",\"styleClass\":null,\"format\":null,\"title\":\"LOB\",\"id\":\"lob\",\"isDisplayed\":true},{\"type\":\"DATE\",\"styleClass\":null,\"format\":null,\"title\":\"Effective\",\"id\":\"effective_date\",\"isDisplayed\":true},{\"type\":\"STATUS\",\"styleClass\":null,\"format\":null,\"title\":\"Status\",\"id\":\"status\",\"isDisplayed\":true},{\"type\":\"DECIMAL\",\"styleClass\":null,\"format\":\"currency: ' '\",\"title\":\"Premium\",\"id\":\"premium\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Code\",\"id\":\"agency_code\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency N"
		"ame\",\"id\":\"agency_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter ID\",\"id\":\"underwriter_id\",\"isDisplayed\":false},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter\",\"id\":\"underwriter_name\",\"isDisplayed\":true},{\"type\":\"TIME\",\"styleClass\":null,\"format\":null,\"title\":\"Updated\",\"id\":\"last_update_time\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Transaction Type\",\"id\":\"transaction_type\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":\"percentage\",\"title\":\"Complete %\",\"id\":\"complete_percent\",\"isDisplayed\":false}],\"type\":\"CARD\",\"viewPortSize\":20,\"startRowNumber\":0,\"selected\":false,\"fetchSize\":20},{\"fields\":[{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"ID\",\"id\":\"work_item_id\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"t"
		"itle\":\"Account Id\",\"id\":\"account_id\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Name\",\"id\":\"entity_name\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Quote Number\",\"id\":\"quote_number\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"LOB\",\"styleClass\":null,\"format\":null,\"title\":\"LOB\",\"id\":\"lob\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"DATE\",\"styleClass\":null,\"format\":null,\"title\":\"Effective\",\"id\":\"effective_date\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"STATUS\",\"styleClass\":null,\"format\":null,\"title\":\"Status\",\"id\":\"status\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"DECIMAL\",\"styleClass\":null,\"format\":\"currency: ' '\",\"title\":\"Premium\",\"id\":\"premium\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Code\",\"id\":\"agenc"
		"y_code\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Name\",\"id\":\"agency_name\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter ID\",\"id\":\"underwriter_id\",\"isDisplayed\":false},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter\",\"id\":\"underwriter_name\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"TIME\",\"styleClass\":null,\"format\":null,\"title\":\"Updated\",\"id\":\"last_update_time\",\"isDisplayed\":true,\"isSortable\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Transaction Type\",\"id\":\"transaction_type\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":\"percentage\",\"title\":\"Complete %\",\"id\":\"complete_percent\",\"isDisplayed\":false}],\"type\":\"TABULAR\",\"viewPortSize\":40,\"startRowNumber\":0,\"selected\":true,\"fetchSize\":40}],\"sav"
		"edSearchInfo\":{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/saved_searches?view_name=WorkItemsView\",\"parameters\":[\"saved_search_id\",\"view_name\"]},\"savedSearches\":[],\"currentSearch\":{\"id\":-1,\"name\":null,\"isActive\":true}},\"lookupLinks\":[{\"rel\":\"lookups.basic.STATUS\",\"href\":\"/api/lookups/basic/STATUS\",\"parameters\":null},{\"rel\":\"lookups.basic.ACCOUNT_TYPE\",\"href\":\"/api/lookups/basic/ACCOUNT_TYPE\",\"parameters\":null},{\"rel\":\"lookups.basic.TRANSACTION_TYPE\",\"href\":\"/api/lookups/basic/TRANSACTION_TYPE\",\"parameters\":null},{\"rel\":\"lookups.basic.LOB\",\"href\":\"/api/lookups/basic/LOB\",\"parameters\":null},{\"rel\":\"lookups.basic.NewWorkItemLink\",\"href\":\"/api/lookups/basic/NewWorkItemLink\",\"parameters\":[\"worklistType\"]}],\"isSaveable\":true,\"newWorkItemLinks\":[{\"title\":\"Commercial Package\",\"value\":\"FrontServlet?PAGE_NAME=generalInfoCPP&TRANSACTION_NAME=cpp&FIRST_TIME=true&METHOD=Display&rnd=0.9056129698183245&CSRF_TOKEN={CSRF_TO"
		"KEN11_1}\"},{\"title\":\"Commercial Auto\",\"value\":\"FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&FIRST_TIME=true&METHOD=Display&rnd=0.5019430315332588&CSRF_TOKEN={CSRF_TOKEN11_1}\"},{\"title\":\"Workers Comp\",\"value\":\"FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&FIRST_TIME=true&METHOD=Display&rnd=0.47921120676313256&CSRF_TOKEN={CSRF_TOKEN11_1}\"}]}",
		LAST);

	
	lr_end_transaction("Agency portal",LR_AUTO);

	lr_start_transaction("commercial auto");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='12d6eb4b264d7b8cf9a01c53beb31be8709798f6ac9e0d7cb11f06401eff9d6f' Name ='CSRF_TOKEN4' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN4",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='2f90af0a927038edd242b72c6e11c43db0c0f7d95df541a2c20ef4af5d00dbf5' Name ='CSRF_TOKEN12_1' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN12_1",
		"RegExp=CSRF_TOKEN=(.*?)\\\r\\\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_url("FrontServlet",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&FIRST_TIME=true&METHOD=Display&rnd=0.5220440702577591&CSRF_TOKEN={CSRF_TOKEN}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t24.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN=2f90af0a927038edd242b72c6e11c43db0c0f7d95df541a2c20ef4af5d00dbf5", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN=2f90af0a927038edd242b72c6e11c43db0c0f7d95df541a2c20ef4af5d00dbf5", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN=2f90af0a927038edd242b72c6e11c43db0c0f7d95df541a2c20ef4af5d00dbf5", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN=2f90af0a927038edd242b72c6e11c43db0c0f7d95df541a2c20ef4af5d00dbf5", ENDITEM,
		"URL=assets/custom/select2/select2.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN=2f90af0a927038edd242b72c6e11c43db0c0f7d95df541a2c20ef4af5d00dbf5", ENDITEM,
		"URL=assets/themes/secura/logo.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN=2f90af0a927038edd242b72c6e11c43db0c0f7d95df541a2c20ef4af5d00dbf5", ENDITEM,
		LAST);

	web_url("data",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN4}&rnd=1513241496276&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t25.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("FileUploadServlet_2",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t26.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=requestType", "Value=list", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_2",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t27.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_revert_auto_header("X-Requested-With");

	

	lr_end_transaction("commercial auto",LR_AUTO);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_submit_data("FrontServlet_3",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t29.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	lr_start_transaction("general information");

	web_submit_data("FrontServlet_4",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t30.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_5",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t31.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_6",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t32.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_7",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t33.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_8",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t34.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_9",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t35.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_10",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t36.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_11",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t37.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='acae90f16e0c19e5e19a791004af38d9ebd3f98518ecd77be132cc0f5e503fd3' Name ='CSRF_TOKEN5' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN5",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_12",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=autob&WORKITEMID=6320&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd=0.766454415685818&CSRF_TOKEN={CSRF_TOKEN12_1}",
		"Snapshot=t38.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=0", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN4}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=SecuraCommlPolicyLOBCd", "Value=AUTOB", ENDITEM,
		"Name=CommlAutoLineBusinessLOBCd", "Value=AUTOB", ENDITEM,
		"Name=SecuraCommlPolicyId", "Value=GUID()", ENDITEM,
		"Name=CommlAutoLineBusinessId", "Value=GUID()", ENDITEM,
		"Name=GenInfoTransactionRequestDt", "Value=SYSTEM_DATE()", ENDITEM,
		"Name=RqUID", "Value=GUID()", ENDITEM,
		"Name=CurCd", "Value=USD", ENDITEM,
		"Name=AccClearanceFieldForIPDTR", "Value=NO", ENDITEM,
		"Name=AccClearanceMultiResultJSON", "Value=", ENDITEM,
		"Name=CreateNewAccountFlag", "Value=N", ENDITEM,
		"Name=SPAGCODE", "Value=", ENDITEM,
		"Name=SPAGNAME", "Value=", ENDITEM,
		"Name=SPACCOUNTNO", "Value=", ENDITEM,
		"Name=SPCUSTNAME", "Value=", ENDITEM,
		"Name=SPDBA", "Value=", ENDITEM,
		"Name=SPADD", "Value=", ENDITEM,
		"Name=SPPHONE", "Value=", ENDITEM,
		"Name=SPFEIN", "Value=", ENDITEM,
		"Name=SPDATE", "Value=", ENDITEM,
		"Name=SPPKG", "Value=", ENDITEM,
		"Name=SPAUTO", "Value=", ENDITEM,
		"Name=SPWC", "Value=", ENDITEM,
		"Name=SPUM", "Value=", ENDITEM,
		"Name=hiddenClearanceOverride", "Value=NO", ENDITEM,
		"Name=ShowFlag", "Value=", ENDITEM,
		"Name=SPClearnceInputChangeFlag", "Value=N", ENDITEM,
		"Name=AgencyName", "Value=20068/LEBARON & CARROLL LLC", ENDITEM,
		"Name=AgencyProducer", "Value=020068BD/ANGELA J//TERLECKI", ENDITEM,
		"Name=AgencyAddr1", "Value=11430 E RUTLEDGE", ENDITEM,
		"Name=AgencyAddr2", "Value=", ENDITEM,
		"Name=AgencyCity", "Value=MESA", ENDITEM,
		"Name=AgencyState", "Value=AZ", ENDITEM,
		"Name=AgencyZip", "Value=85212", ENDITEM,
		"Name=AgentCSRPhone", "Value=", ENDITEM,
		"Name=AgencyPhone", "Value=", ENDITEM,
		"Name=AgencyEmail", "Value=", ENDITEM,
		"Name=GenInfoMessage", "Value=Address has been updated and standardized, please continue.", ENDITEM,
		"Name=GenInfoMultiResultJSON", "Value=", ENDITEM,
		"Name=EffectiveDate", "Value=12-14-2017", ENDITEM,
		"Name=EffectiveDateUWOR", "Value=false", ENDITEM,
		"Name=ExpirationDate", "Value=12-14-2018", ENDITEM,
		"Name=ApplicantName", "Value=Douglas", ENDITEM,
		"Name=DoingBusinessAs", "Value=", ENDITEM,
		"Name=ApplicantMailingCountry", "Value=USA", ENDITEM,
		"Name=ApplicantMailingAddress1", "Value=2401 S Memorial Dr", ENDITEM,
		"Name=ApplicantMailingAddress2", "Value=", ENDITEM,
		"Name=ApplicantMailingCity", "Value=Appleton", ENDITEM,
		"Name=ApplicantMailingState", "Value=WI", ENDITEM,
		"Name=ApplicantMailingZip_US", "Value=54915-1429", ENDITEM,
		"Name=ApplicantMailingGEOPlaceCd", "Value=5502375", ENDITEM,
		"Name=ApplicantMailingGEOCensusTract", "Value=002500", ENDITEM,
		"Name=ApplicantMailingGEOCensusBlock", "Value=2017", ENDITEM,
		"Name=ApplicantMailingGEOCountyFIPS", "Value=55139", ENDITEM,
		"Name=ApplicantMailingGEOLatitude", "Value=44.238404", ENDITEM,
		"Name=ApplicantMailingGEOLongitude", "Value=-88.42148", ENDITEM,
		"Name=ApplicantMailingGEOResult", "Value=GS01", ENDITEM,
		"Name=ApplicantMailingGEOCountyName", "Value=Winnebago", ENDITEM,
		"Name=ApplicantMailingGEOSubdivisionCode", "Value=02375", ENDITEM,
		"Name=ApplicantMailingAddressValidationFlag", "Value=EXACTMATCH", ENDITEM,
		"Name=ApplicantPhone", "Value=", ENDITEM,
		"Name=DateBusinessStart", "Value=12-05-2017", ENDITEM,
		"Name=NamedInsuredExternalId", "Value=", ENDITEM,
		"Name=WebsiteAddress", "Value=", ENDITEM,
		"Name=EMailAddress", "Value=", ENDITEM,
		"Name=ApplicantLegalEntity", "Value=CP", ENDITEM,
		"Name=TaxIdType", "Value=FEIN", ENDITEM,
		"Name=TaxIdFEIN", "Value=", ENDITEM,
		"Name=PMA", "Value=", ENDITEM,
		"Name=PrimaryBusDescription", "Value=50010", ENDITEM,
		"Name=HazardGrade", "Value=", ENDITEM,
		"Name=NatureofBusiness", "Value=", ENDITEM,
		"Name=MarketSegment", "Value=C", ENDITEM,
		"Name=ApplicantSICCode", "Value=3291", ENDITEM,
		"Name=ApplicantNAICSCode", "Value=327910", ENDITEM,
		"Name=ControllingState", "Value=WI", ENDITEM,
		"Name=ProgramAssociation", "Value=", ENDITEM,
		"Name=InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore", "Value=", ENDITEM,
		"Name=OperationOfHazardousMaterial", "Value=NO", ENDITEM,
		"Name=LossPast3Years", "Value=NLOSS", ENDITEM,
		"Name=Underwriter", "Value=BE02733", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		LAST);

	web_url("data_2",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN5}&rnd=1513241641826&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t39.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_custom_request("FrontServlet_13",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t40.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH=-1468985806&WORKITEMID=6320&TRANSACTION_NAME=autob&PAGE_NAME=Locations&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN5}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&LocationId=GUID()&LocationSystemId=&hiddenAccountClearanceStatus=&MultiResultJSON=&LocationNumber=&LocationDescription=&LocationAddressAddr1=&LocationAddressAddr2=&LocationAddressCity=&LocationAddressState=&LocationAddressZip=&LocationGEOResult=&LocationGEOPlaceCd=&LocationGEOCensusTract=&LocationGEOCensusBlock=&LocationGEOCountyFIPS=&LocationGEOLatitude=&LocationGEOLongitude=&LocationGEOCountyName=&LocationGEOSubdivisionCode=&LocationAddressAddressValidationFlag=&INDEX.Location=Location%5B1%5D",
		LAST);

	web_submit_data("FrontServlet_14",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t41.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN5}", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_3", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("general information",LR_AUTO);

	web_submit_data("FrontServlet_15",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t43.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN5}", ENDITEM,
		LAST);

	lr_start_transaction("edit garging location");

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='09aa3015e7d71af9d9afe2371ae44f06634e5b52964bc963b8d36116c205f4b5' Name ='CSRF_TOKEN6' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN6",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_url("FrontServlet_16",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t44.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}", ENDITEM,
		"URL=assets/themes/secura/logo.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}", ENDITEM,
		LAST);

	web_url("data_3",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN6}&rnd=1513241671085&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}",
		"Snapshot=t45.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_submit_data("FrontServlet_17",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}",
		"Snapshot=t46.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=-1112153510", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN6}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=LocationId", "Value=N73", ENDITEM,
		"Name=LocationSystemId", "Value=", ENDITEM,
		"Name=hiddenAccountClearanceStatus", "Value=", ENDITEM,
		"Name=MultiResultJSON", "Value=", ENDITEM,
		"Name=LocationNumber", "Value=", ENDITEM,
		"Name=LocationDescription", "Value=", ENDITEM,
		"Name=LocationAddressAddr1", "Value=2401 S Memorial Dr", ENDITEM,
		"Name=LocationAddressAddr2", "Value=", ENDITEM,
		"Name=LocationAddressCity", "Value=Appleton", ENDITEM,
		"Name=LocationAddressState", "Value=WI", ENDITEM,
		"Name=LocationAddressZip", "Value=54915-1429", ENDITEM,
		"Name=LocationGEOResult", "Value=GS01", ENDITEM,
		"Name=LocationGEOPlaceCd", "Value=5502375", ENDITEM,
		"Name=LocationGEOCensusTract", "Value=002500", ENDITEM,
		"Name=LocationGEOCensusBlock", "Value=2017", ENDITEM,
		"Name=LocationGEOCountyFIPS", "Value=55139", ENDITEM,
		"Name=LocationGEOLatitude", "Value=44.238404", ENDITEM,
		"Name=LocationGEOLongitude", "Value=-88.42148", ENDITEM,
		"Name=LocationGEOCountyName", "Value=Winnebago", ENDITEM,
		"Name=LocationGEOSubdivisionCode", "Value=02375", ENDITEM,
		"Name=LocationAddressAddressValidationFlag", "Value=EXACTMATCH", ENDITEM,
		"Name=INDEX.Location", "Value=Location[0]", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_4",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}",
		"Snapshot=t47.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=requestType", "Value=list", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_18",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}",
		"Snapshot=t48.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN6}", ENDITEM,
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='c23d8cc6d53a6188499570e217853cb796c80c70067db5db3aa2010e629f1027' Name ='CSRF_TOKEN7' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN7",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_19",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=Locations&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.Location=Location[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN5}",
		"Snapshot=t49.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=-1112153510", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN6}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=Save", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=LocationId", "Value=N73", ENDITEM,
		"Name=LocationSystemId", "Value=", ENDITEM,
		"Name=hiddenAccountClearanceStatus", "Value=", ENDITEM,
		"Name=MultiResultJSON", "Value=", ENDITEM,
		"Name=LocationNumber", "Value=1", ENDITEM,
		"Name=LocationDescription", "Value=", ENDITEM,
		"Name=LocationAddressAddr1", "Value=2401 S Memorial Dr", ENDITEM,
		"Name=LocationAddressAddr2", "Value=", ENDITEM,
		"Name=LocationAddressCity", "Value=Appleton", ENDITEM,
		"Name=LocationAddressState", "Value=WI", ENDITEM,
		"Name=LocationAddressZip", "Value=54915-1429", ENDITEM,
		"Name=LocationGEOResult", "Value=GS01", ENDITEM,
		"Name=LocationGEOPlaceCd", "Value=5502375", ENDITEM,
		"Name=LocationGEOCensusTract", "Value=002500", ENDITEM,
		"Name=LocationGEOCensusBlock", "Value=2017", ENDITEM,
		"Name=LocationGEOCountyFIPS", "Value=55139", ENDITEM,
		"Name=LocationGEOLatitude", "Value=44.238404", ENDITEM,
		"Name=LocationGEOLongitude", "Value=-88.42148", ENDITEM,
		"Name=LocationGEOCountyName", "Value=Winnebago", ENDITEM,
		"Name=LocationGEOSubdivisionCode", "Value=02375", ENDITEM,
		"Name=LocationAddressAddressValidationFlag", "Value=EXACTMATCH", ENDITEM,
		"Name=INDEX.Location", "Value=Location[0]", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		LAST);

	web_url("data_4",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN7}&rnd=1513241682431&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t50.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_custom_request("FrontServlet_20",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t51.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH=644338265&WORKITEMID=6320&TRANSACTION_NAME=autob&PAGE_NAME=Locations&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN7}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&LocationId=GUID()&LocationSystemId=&hiddenAccountClearanceStatus=&MultiResultJSON=&LocationNumber=&LocationDescription=&LocationAddressAddr1=&LocationAddressAddr2=&LocationAddressCity=&LocationAddressState=&LocationAddressZip=&LocationGEOResult=&LocationGEOPlaceCd=&LocationGEOCensusTract=&LocationGEOCensusBlock=&LocationGEOCountyFIPS=&LocationGEOLatitude=&LocationGEOLongitude=&LocationGEOCountyName=&LocationGEOSubdivisionCode=&LocationAddressAddressValidationFlag=&INDEX.Location=Location%5B1%5D",
		LAST);

	web_submit_data("FileUploadServlet_5", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_submit_data("FrontServlet_21",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t53.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN7}", ENDITEM,
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='ddc03e1b6cf0d577273db3b4ef06fd462e4a31d6cf11876aa7bd1f1a88d46ad7' Name ='CSRF_TOKEN8' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN8",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_22",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t54.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=644338265", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN7}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=LocationId", "Value=GUID()", ENDITEM,
		"Name=LocationSystemId", "Value=", ENDITEM,
		"Name=hiddenAccountClearanceStatus", "Value=", ENDITEM,
		"Name=MultiResultJSON", "Value=", ENDITEM,
		"Name=LocationNumber", "Value=", ENDITEM,
		"Name=LocationDescription", "Value=", ENDITEM,
		"Name=LocationAddressAddr1", "Value=", ENDITEM,
		"Name=LocationAddressAddr2", "Value=", ENDITEM,
		"Name=LocationAddressCity", "Value=", ENDITEM,
		"Name=LocationAddressState", "Value=", ENDITEM,
		"Name=LocationAddressZip", "Value=", ENDITEM,
		"Name=LocationGEOResult", "Value=", ENDITEM,
		"Name=LocationGEOPlaceCd", "Value=", ENDITEM,
		"Name=LocationGEOCensusTract", "Value=", ENDITEM,
		"Name=LocationGEOCensusBlock", "Value=", ENDITEM,
		"Name=LocationGEOCountyFIPS", "Value=", ENDITEM,
		"Name=LocationGEOLatitude", "Value=", ENDITEM,
		"Name=LocationGEOLongitude", "Value=", ENDITEM,
		"Name=LocationGEOCountyName", "Value=", ENDITEM,
		"Name=LocationGEOSubdivisionCode", "Value=", ENDITEM,
		"Name=LocationAddressAddressValidationFlag", "Value=", ENDITEM,
		"Name=INDEX.Location", "Value=Location[1]", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		LAST);

	web_url("data_5",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN8}&rnd=1513241693013&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t55.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_submit_data("FrontServlet_23",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t56.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=policyCoverages", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN8}", ENDITEM,
		LAST);

	web_custom_request("FrontServlet_24",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t57.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH=644338265&WORKITEMID=6320&TRANSACTION_NAME=autob&PAGE_NAME=policyCoverages&force_view_on_upload=true&CSRF_TOKEN={CSRF_TOKEN8}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&CommlAutoLineBusiness.CommlRateState.%40id=GUID()&AutoWrapCovInd=1&HotRateState=&MarketSegmentValue=C&HiddenControllingState=WI&LiabilityLimitCSL=1000000&hiddenPropertyDamageLiabilityDeductibleCheck=0&hiddenPropertyDamageLiablityDeductibleAmount=&UninsuredMotorist=1&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D",
		LAST);

	web_submit_data("FileUploadServlet_6", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("edit garging location",LR_AUTO);
	
	/*Correlation comment - Do not change!  Original value='82c58652c07c8a25f52633cd235624416c4edf1e7a7de914d193b8dbb92b344a' Name ='CSRF_TOKEN9' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN9",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	lr_start_transaction("policy coverages");

	web_submit_data("FrontServlet_25",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t59.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=policyCoverages", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN8}", ENDITEM,
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

//CSRF_TOKEN9

/*Correlation comment - Do not change!  Original value='2008140159' Name ='HASH' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=HASH",
		"TagName=input",
		"Extract=value",
		"Name=HASH",
		"Id=HASH",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_url("FrontServlet_26",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t60.inf",
		"Mode=HTTP",
		/*EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}", ENDITEM,
		"URL=assets/themes/secura/logo.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}", ENDITEM,*/
		LAST);

	web_url("data_6",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN9}&rnd=1513241713268&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}",
		"Snapshot=t61.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_submit_data("FrontServlet_27",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}",
		"Snapshot=t62.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH}", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=policyCoverages", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN9}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.@id", "Value=N88", ENDITEM,
		"Name=HotRateState", "Value=WI", ENDITEM,
		"Name=MarketSegmentValue", "Value=C", ENDITEM,
		"Name=HiddenControllingState", "Value=WI", ENDITEM,
		"Name=LiabilityLimitCSL", "Value=1000000", ENDITEM,
		"Name=hiddenPropertyDamageLiabilityDeductibleCheck", "Value=0", ENDITEM,
		"Name=hiddenPropertyDamageLiablityDeductibleAmount", "Value=", ENDITEM,
		"Name=MedicalPaymentCheck", "Value=1", ENDITEM,
		"Name=UninsuredMotorist", "Value=1", ENDITEM,
		"Name=UnderinsuredMotorist", "Value=1", ENDITEM,
		"Name=SymbolsLiability", "Value=", ENDITEM,
		"Name=SymbolsMedicalPayments", "Value=", ENDITEM,
		"Name=SymbolsUninsuredMotorist", "Value=", ENDITEM,
		"Name=SymbolsUnderinsuredMotorist", "Value=", ENDITEM,
		"Name=SymbolsTowingLabor", "Value=", ENDITEM,
		"Name=SymbolsComprehensive", "Value=", ENDITEM,
		"Name=SymbolsSpecifiedCausesofLoss", "Value=", ENDITEM,
		"Name=SymbolsCollision", "Value=", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_7",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}",
		"Snapshot=t63.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=requestType", "Value=list", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_28",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}",
		"Snapshot=t64.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=policyCoverages", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN9}", ENDITEM,
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='32f309c8498ecc75a444b4df4b90d3713607ef66c7f6bade65dcf703137450f2' Name ='CSRF_TOKEN10' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN10",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='901246515' Name ='HASH_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=HASH_1",
		"TagName=input",
		"Extract=value",
		"Name=HASH",
		"Id=HASH",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_29",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=policyCoverages&METHOD=Display&TRANSACTION_NAME=autob&WORKITEMID=6320&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN8}",
		"Snapshot=t65.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH}", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=policyCoverages", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN9}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=Save", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.@id", "Value=N88", ENDITEM,
		"Name=AutoWrapCovInd", "Value=1", ENDITEM,
		"Name=HotRateState", "Value=WI", ENDITEM,
		"Name=MarketSegmentValue", "Value=C", ENDITEM,
		"Name=HiddenControllingState", "Value=WI", ENDITEM,
		"Name=LiabilityLimitCSL", "Value=1000000", ENDITEM,
		"Name=hiddenPropertyDamageLiabilityDeductibleCheck", "Value=0", ENDITEM,
		"Name=hiddenPropertyDamageLiablityDeductibleAmount", "Value=", ENDITEM,
		"Name=MedicalPaymentCheck", "Value=1", ENDITEM,
		"Name=MedicalPaymentLimitEachPerson", "Value=5000", ENDITEM,
		"Name=UninsuredMotorist", "Value=1", ENDITEM,
		"Name=UninsuredMotoristCSLLimit", "Value=1000000", ENDITEM,
		"Name=UnderinsuredMotorist", "Value=1", ENDITEM,
		"Name=UnderinsuredMotoristLimitCSL", "Value=1000000", ENDITEM,
		"Name=SymbolsLiability", "Value=", ENDITEM,
		"Name=SymbolsMedicalPayments", "Value=", ENDITEM,
		"Name=SymbolsUninsuredMotorist", "Value=", ENDITEM,
		"Name=SymbolsUnderinsuredMotorist", "Value=", ENDITEM,
		"Name=SymbolsTowingLabor", "Value=", ENDITEM,
		"Name=SymbolsComprehensive", "Value=", ENDITEM,
		"Name=SymbolsSpecifiedCausesofLoss", "Value=", ENDITEM,
		"Name=SymbolsCollision", "Value=", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[0]", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		LAST);

	web_url("data_7",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN10}&rnd=1513241726367&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t66.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("FrontServlet_30",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t67.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=policyCoverages", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN10}", ENDITEM,
		LAST);

	web_custom_request("FrontServlet_31",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t68.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH_1}&WORKITEMID=6320&TRANSACTION_NAME=autob&PAGE_NAME=policyCoverages&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN10}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&CommlAutoLineBusiness.CommlRateState.%40id=GUID()&AutoWrapCovInd=1&HotRateState=&MarketSegmentValue=C&HiddenControllingState=WI&LiabilityLimitCSL=1000000&hiddenPropertyDamageLiabilityDeductibleCheck=0&hiddenPropertyDamageLiablityDeductibleAmount=&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D&INDEX.CommlAutoLineBusiness.CommlRateState=CommlAutoLineBusiness.CommlRateState%5B1%5D",
		LAST);

	web_submit_data("FileUploadServlet_8", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='0a8e669843a907933e3993d08e0dc4c40bad6f1337599aee001bb1fb92ae236f' Name ='CSRF_TOKEN11' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN11",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_32",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t70.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_1}", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=policyCoverages", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN10}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.@id", "Value=GUID()", ENDITEM,
		"Name=AutoWrapCovInd", "Value=1", ENDITEM,
		"Name=HotRateState", "Value=", ENDITEM,
		"Name=MarketSegmentValue", "Value=C", ENDITEM,
		"Name=HiddenControllingState", "Value=WI", ENDITEM,
		"Name=LiabilityLimitCSL", "Value=1000000", ENDITEM,
		"Name=hiddenPropertyDamageLiabilityDeductibleCheck", "Value=0", ENDITEM,
		"Name=hiddenPropertyDamageLiablityDeductibleAmount", "Value=", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[1]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[1]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[1]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[1]", ENDITEM,
		"Name=INDEX.CommlAutoLineBusiness.CommlRateState", "Value=CommlAutoLineBusiness.CommlRateState[1]", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", "XMLHttpRequest");

	web_custom_request("FrontServlet_33",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t71.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH_1}&WORKITEMID=6320&TRANSACTION_NAME=autob&PAGE_NAME=vehicle&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN11}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&CommlAutoLineBusiness.CommlRateState.%40id=GUID()&CommlAutoLineBusiness.CommlRateState.CommlVeh.%40id=GUID()&VinMultiResultJSON=&NewVinServiceCallInd=&vinValidated=N%2FA&VinValidatedMessageFlag=&CommlAutoLineBusiness.CommlRateState.CommlVeh.HotGaragedLocationRef=&HotVehicleType=&vinNumber=&year=&make=&model=&MultiResultVINJSON=&grossVehicleCombinedWeight=&GrossVehicleCombinedWeightOverRideValue=&HotRegisteredState=&vehicleModelNum=&vehicleDescription=&engineType=&VehPropertyDamageLiablityDeductible=ND&VehPDLiablityDedDefaultFlag=Yes&ComprehensiveDeductible=NC&CompType=Comprehensive&FullGlassCoverageDefaultFlag=Yes&CollisionDeductible=NC&pdCostNewOverride=",
		LAST);

	web_url("data_8",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN11}&rnd=1513241734330&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t72.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_submit_data("FileUploadServlet_9", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t73.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_submit_data("FrontServlet_34",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t74.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=vehicle", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN11}", ENDITEM,
		LAST);

	lr_end_transaction("policy coverages",LR_AUTO);

	lr_start_transaction("vehicles");

	web_submit_data("FrontServlet_35",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t75.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=vehicle", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN11}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_36",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t76.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=vehicle", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN11}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_37",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t77.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=vehicle", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN11}", ENDITEM,
		LAST);

	web_custom_request("FrontServlet_38",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=1",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t78.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH_1}&WORKITEMID=6320&TRANSACTION_NAME=autob&PAGE_NAME=vehicle&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN11}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&CommlAutoLineBusiness.CommlRateState.%40id=GUID()&CommlAutoLineBusiness.CommlRateState.CommlVeh.%40id=GUID()&VinMultiResultJSON=&NewVinServiceCallInd=OldVin&vinValidated=Yes&VinValidatedMessageFlag=VALIDVIN&CommlAutoLineBusiness.CommlRateState.CommlVeh.HotGaragedLocationRef=N73&HotVehicleType=PP&vinNumber=1GDL7C1E85F525005&year=2005&make=GMC%5CCHEVY&model=C7CO42&MultiResultVINJSON=&grossVehicleCombinedWeight=24640&GrossVehicleCombinedWeightOverRideValue=24640&HotRegisteredState=&vehicleModelNum=C7CO42+(*7C1*)&vehicleDescription=C7500+Series+4x2+105%22+BBC+Conv.+Chs-Cab+w%2FDual+Power-Hyd+Brakes&engineType=Vortec+8100-295+GMA&useMileagePP=CM&OperatorExperiencePP=&VehPropertyDamageLiablityDeductible=ND&VehPDLiablityDedDefaultFlag=Yes&ComprehensiveDeductible=1000&CompType=Comprehensive&FullGlassCoverageDefaultFlag=Yes&CollisionDeductible=500&"
		"ValuationMethod=A&pdCostNewOverride=42475&pdCostNew=42475&AutoLoanLeaseGapCoverage=1&TowingAndLaborLimit=",
		LAST);

	web_submit_data("FrontServlet_39",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t79.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=vehicle", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN11}", ENDITEM,
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='64efd54dcc636010e18814df47a2c527e319c5717c7df82a552569571b12ddb3' Name ='CSRF_TOKEN12' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN12",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_40",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t80.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_1}", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=vehicle", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN11}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Add", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.@id", "Value=GUID()", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.CommlVeh.@id", "Value=GUID()", ENDITEM,
		"Name=VinMultiResultJSON", "Value=", ENDITEM,
		"Name=NewVinServiceCallInd", "Value=OldVin", ENDITEM,
		"Name=vinValidated", "Value=Yes", ENDITEM,
		"Name=VinValidatedMessageFlag", "Value=VALIDVIN", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.CommlVeh.HotGaragedLocationRef", "Value=N73", ENDITEM,
		"Name=HotVehicleType", "Value=PP", ENDITEM,
		"Name=vinNumber", "Value=1GDL7C1E85F525005", ENDITEM,
		"Name=year", "Value=2005", ENDITEM,
		"Name=make", "Value=GMC\\CHEVY", ENDITEM,
		"Name=model", "Value=C7CO42", ENDITEM,
		"Name=MultiResultVINJSON", "Value=", ENDITEM,
		"Name=grossVehicleCombinedWeight", "Value=24640", ENDITEM,
		"Name=GrossVehicleCombinedWeightOverRideValue", "Value=24640", ENDITEM,
		"Name=HotRegisteredState", "Value=", ENDITEM,
		"Name=vehicleModelNum", "Value=C7CO42 (*7C1*)", ENDITEM,
		"Name=vehicleDescription", "Value=C7500 Series 4x2 105\" BBC Conv. Chs-Cab w/Dual Power-Hyd Brakes", ENDITEM,
		"Name=engineType", "Value=Vortec 8100-295 GMA", ENDITEM,
		"Name=useMileagePP", "Value=CM", ENDITEM,
		"Name=OperatorExperiencePP", "Value=", ENDITEM,
		"Name=VehPropertyDamageLiablityDeductible", "Value=ND", ENDITEM,
		"Name=VehPDLiablityDedDefaultFlag", "Value=Yes", ENDITEM,
		"Name=ComprehensiveDeductible", "Value=1000", ENDITEM,
		"Name=CompType", "Value=Comprehensive", ENDITEM,
		"Name=FullGlassCoverageDefaultFlag", "Value=Yes", ENDITEM,
		"Name=CollisionDeductible", "Value=500", ENDITEM,
		"Name=ValuationMethod", "Value=A", ENDITEM,
		"Name=pdCostNewOverride", "Value=42475", ENDITEM,
		"Name=pdCostNew", "Value=42475", ENDITEM,
		"Name=AutoLoanLeaseGapCoverage", "Value=1", ENDITEM,
		"Name=TowingAndLaborLimit", "Value=", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		LAST);

	web_url("data_9",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN12}&rnd=1513241803545&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t81.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_custom_request("FrontServlet_41",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t82.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH_1}&WORKITEMID=6320&TRANSACTION_NAME=autob&PAGE_NAME=vehicle&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN12}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&CommlAutoLineBusiness.CommlRateState.%40id=GUID()&CommlAutoLineBusiness.CommlRateState.CommlVeh.%40id=GUID()&VinMultiResultJSON=&NewVinServiceCallInd=&vinValidated=N%2FA&VinValidatedMessageFlag=&CommlAutoLineBusiness.CommlRateState.CommlVeh.HotGaragedLocationRef=&HotVehicleType=&vinNumber=&year=&make=&model=&MultiResultVINJSON=&grossVehicleCombinedWeight=&GrossVehicleCombinedWeightOverRideValue=&HotRegisteredState=&vehicleModelNum=&vehicleDescription=&engineType=&VehPropertyDamageLiablityDeductible=ND&VehPDLiablityDedDefaultFlag=Yes&ComprehensiveDeductible=1000&CompType=Comprehensive&FullGlassCoverageDefaultFlag=Yes&CollisionDeductible=NC&pdCostNewOverride=",
		LAST);

	web_submit_data("FileUploadServlet_10", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t83.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_submit_data("FrontServlet_42",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t84.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=vehicle", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN12}", ENDITEM,
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", LAST);

/*Correlation comment - Do not change!  Original value='42cda2b481a3ed57f005c29a413beb7e3ae78d08495b6f9ca33b6f10e2bd3565' Name ='CSRF_TOKEN13' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN13",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_43",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t85.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_1}", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=vehicle", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN12}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.@id", "Value=GUID()", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.CommlVeh.@id", "Value=GUID()", ENDITEM,
		"Name=VinMultiResultJSON", "Value=", ENDITEM,
		"Name=NewVinServiceCallInd", "Value=", ENDITEM,
		"Name=vinValidated", "Value=N/A", ENDITEM,
		"Name=VinValidatedMessageFlag", "Value=", ENDITEM,
		"Name=CommlAutoLineBusiness.CommlRateState.CommlVeh.HotGaragedLocationRef", "Value=", ENDITEM,
		"Name=HotVehicleType", "Value=", ENDITEM,
		"Name=vinNumber", "Value=", ENDITEM,
		"Name=year", "Value=", ENDITEM,
		"Name=make", "Value=", ENDITEM,
		"Name=model", "Value=", ENDITEM,
		"Name=MultiResultVINJSON", "Value=", ENDITEM,
		"Name=grossVehicleCombinedWeight", "Value=", ENDITEM,
		"Name=GrossVehicleCombinedWeightOverRideValue", "Value=", ENDITEM,
		"Name=HotRegisteredState", "Value=", ENDITEM,
		"Name=vehicleModelNum", "Value=", ENDITEM,
		"Name=vehicleDescription", "Value=", ENDITEM,
		"Name=engineType", "Value=", ENDITEM,
		"Name=VehPropertyDamageLiablityDeductible", "Value=ND", ENDITEM,
		"Name=VehPDLiablityDedDefaultFlag", "Value=Yes", ENDITEM,
		"Name=ComprehensiveDeductible", "Value=1000", ENDITEM,
		"Name=CompType", "Value=Comprehensive", ENDITEM,
		"Name=FullGlassCoverageDefaultFlag", "Value=Yes", ENDITEM,
		"Name=CollisionDeductible", "Value=NC", ENDITEM,
		"Name=pdCostNewOverride", "Value=", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		LAST);

	web_url("data_10",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID=6320&CSRF_TOKEN={CSRF_TOKEN13}&rnd=1513241815614&transaction_id=autob",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t86.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_submit_data("FrontServlet_44",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t87.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_1}", ENDITEM,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=AdditionalCoveragePage", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN13}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		EXTRARES,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_11", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t88.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_submit_data("FrontServlet_45",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t89.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value=6320", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=autob", ENDITEM,
		"Name=PAGE_NAME", "Value=AdditionalCoveragePage", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN13}", ENDITEM,
		LAST);

	lr_end_transaction("vehicles",LR_AUTO);

	return 0;
}