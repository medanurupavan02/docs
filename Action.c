Action()
{

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_reg_find("Text=AgentLink", 
		LAST);

	web_url("qa-agentlink.secura.net", 
		"URL=https://qa-agentlink.secura.net/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/AgentLink/fonts/Gotham/Gotham-Black.otf", ENDITEM, 
		"Url=/AgentLink/fonts/glyphicons-halflings-regular.eot?", ENDITEM, 
		"Url=/AgentLink/fonts/fontawesome-webfont.eot?", ENDITEM, 
		LAST);

	web_reg_find("Text=AgentLink", 
		LAST);

	web_url("favicon.ico", 
		"URL=https://qa-agentlink.secura.net/favicon.ico", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		/*EXTRARES, 
		"Url=https://iecvlist.microsoft.com/ie11blocklist/1401746408/versionlist.xml", "Referer=", ENDITEM, */
		LAST);

	lr_start_transaction("01_WC_01_LoginPage");

	web_reg_find("Text=Redirect", 
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
		"Name=httpd_username", "Value={AgentName}", ENDITEM, 
		"Name=httpd_password", "Value=Portal123*", ENDITEM, 
		LAST);

	/*web_reg_find("Text=AgentLink", 
		LAST);

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("favicon.ico_2", 
		"URL=https://qa-agentlink.secura.net/favicon.ico", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_find("Text=AgentLink", 
		LAST);*/

	web_url("AgentLink", 
		"URL=https://qa-agentlink.secura.net/AgentLink", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		/*EXTRARES, 
		"Url=/AgentLink/fonts/Gotham/Gotham-Black.otf", ENDITEM, 
		"Url=/AgentLink/fonts/glyphicons-halflings-regular.eot?", ENDITEM, 
		"Url=/AgentLink/fonts/fontawesome-webfont.eot?", ENDITEM, 
		"Url=https://www.google-analytics.com/analytics.js", ENDITEM, */
		LAST);

	lr_end_transaction("01_WC_01_LoginPage",LR_AUTO);

	lr_start_transaction("01_WC_02_AgencyPortal");

	web_reg_find("Text=agencyportal", 
		LAST);

/*Correlation comment - Do not change!  Original value='9bc17705d7e2c3d455d97f0321b921997523692ae12fddd8c12d49adf4c703f2' Name ='CSRF_TOKEN' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/DisplayWorkInProgress*",
		LAST);

/*Correlation comment - Do not change!  Original value='0.1570518057781030' Name ='rnd' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=rnd",
		"RegExp=rnd=(.*?)&",
		"Ordinal=6",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/DisplayWorkInProgress*",
		LAST);

	web_url("Agency Portal", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgentLink", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		/*EXTRARES, 
		"Url=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		"Url=assets/fonts/font-awesome/fontawesome-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		"Url=assets/themes/secura/logo.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		"Url=assets/themes/secura/orangebar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, 
		"Url=assets/themes/secura/colorbar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", ENDITEM, */
		LAST);

	web_url("messages.tpl.jsp", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/shared/partials/messages.tpl.jsp", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("cardView.jsp", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/worklist/partials/cardView.jsp", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

/*Correlation comment - Do not change!  Original value='727e8a7c043744916e6d85659e9761998ba2fe55689a1aa8996b828a5c1feafb' Name ='CSRF_TOKEN1' Type ='Manual'*/
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
		"Snapshot=t9.inf",
		"Mode=HTML",
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

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

/*Correlation comment - Do not change!  Original value='7810632145b55c393ea614a58710386f2993272fb10856702c4c5fd38616c78d' Name ='CSRF_TOKEN2' Type ='Manual'*/
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
		"Snapshot=t11.inf",
		"Mode=HTML",
		LAST);

/*Correlation comment - Do not change!  Original value='043d2b8d8c524f9eca08270b06ac614aa8b90de65dea0aa5b971d3398cad9b00' Name ='CSRF_TOKEN4' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN4",
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
		"Snapshot=t12.inf",
		"Mode=HTML",
		LAST);


	web_url("worklist-addnewcard.tpl.jsp", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/worklist/partials/worklist-addnewcard.tpl.jsp", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("NewWorkItemLink_2",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/NewWorkItemLink?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t15.inf",
		"Mode=HTML",
		LAST);

	web_url("ACCOUNT_TYPE",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/ACCOUNT_TYPE?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t16.inf",
		"Mode=HTML",
		LAST);

	web_url("LOB",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/LOB?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t17.inf",
		"Mode=HTML",
		LAST);

	web_url("STATUS",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/STATUS?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t18.inf",
		"Mode=HTML",
		LAST);

	web_url("TRANSACTION_TYPE",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/lookups/basic/TRANSACTION_TYPE?CSRF_TOKEN={CSRF_TOKEN1}&listId=WorkItemsView&worklistType=workitems",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t19.inf",
		"Mode=HTML",
		LAST);

/*Correlation comment - Do not change!  Original value='b405ab69f13b66a223d1404d31b1a458502c17ad87266c41d1049d4eecf5eb91' Name ='CSRF_TOKEN3' Type ='Manual'*/
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
	   "Body={\"csrftokenname\":\"CSRF_TOKEN\",\"csrftoken\":\"{CSRF_TOKEN1}\",\"searchName\":-1,\"listId\":\"WorkItemsView\",\"worklistType\":\"workitems\",\"CSRF_TOKEN\":\"{CSRF_TOKEN1}\",\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/views/WorkItemsView\",\"parameters\":[\"saved_search_id\"]},\"name\":\"WorkItemsView\",\"title\":\"Worklist View\",\"version\":\"5.4.0-0\",\"index\":\""
		"worklist\",\"filters\":[{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/filter_infos/lob?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"lob\",\"title\":\"LOB\",\"filterOptions\":[{\"title\":\"Commercial Auto\",\"value\":\"AUTOB\",\"selected\":false},{\"title\":\"Commercial Package\",\"value\":\"CPKGE\",\"selected\":false},{\"title\":\"Workers' Comp\",\"value\":\"WORK\",\"selected\":false}],\"styleClass\":null,\"format\":null,\"relatedFieldId\":\"lob\",\"type\""
		":\"LOB\",\"isSaveable\":true},{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/filter_infos/status?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"status\",\"title\":\"Status\",\"filterOptions\":[{\"title\":\"Closed\",\"value\":\"CLOSED\",\"selected\":false},{\"title\":\"In-Progress\",\"value\":\"INPROGRESS\",\"selected\":false},{\"title\":\"Ineligible / Clearance Approved\",\"value\":\"APPROVEINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Ineligible / "
		"Clearance Declined\",\"value\":\"REJECTINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Ineligible / Clearance Referred\",\"value\":\"REFERINELIGIBLECLEARANCE\",\"selected\":false},{\"title\":\"Issued\",\"value\":\"ISSUED\",\"selected\":false},{\"title\":\"Referred to UW\",\"value\":\"REFER\",\"selected\":false},{\"title\":\"SECURA In-Progress\",\"value\":\"SECURAINPROGRESS\",\"selected\":false},{\"title\":\"SECURA Pending\",\"value\":\"SECURAPENDING\",\"selected\":false},{\"title\":\""
		"Submitted for Issuance\",\"value\":\"SUBMITTEDFORISSUANCE\",\"selected\":false},{\"title\":\"UW Approved\",\"value\":\"APPROVE\",\"selected\":false},{\"title\":\"UW Declined\",\"value\":\"DECLINE\",\"selected\":false}],\"styleClass\":null,\"format\":null,\"relatedFieldId\":\"status\",\"type\":\"STATUS\",\"isSaveable\":true}],\"sortInfo\":{\"link\":{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/sort_info?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},\"name\":\"workitem_sort_by\","
		"\"title\":\"Sort By\",\"sortOptions\":[{\"relatedFieldId\":\"entity_name\",\"title\":\"Name\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"quote_number\",\"title\":\"Quote Number\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"lob\",\"title\":\"LOB\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"effective_date\",\"title\":\"Effective\",\"ascending\":false,\"selected\":false,\"isSaveable\""
		":true},{\"relatedFieldId\":\"status\",\"title\":\"Status\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"premium\",\"title\":\"Premium\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"user_group_id\",\"title\":\"Agency Code\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"agency_name\",\"title\":\"Agency Name\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\""
		"underwriter_name\",\"title\":\"Underwriter\",\"ascending\":false,\"selected\":false,\"isSaveable\":true},{\"relatedFieldId\":\"last_update_time\",\"title\":\"Updated\",\"ascending\":false,\"selected\":true,\"isSaveable\":true}]},\"queryInfo\":{\"name\":\"workitem_query_info\",\"title\":\"More Options\",\"queryFields\":[{\"relatedFieldId\":\"quote_number\",\"title\":\"Quote Number\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\""
		"quoteNumber\",\"isSaveable\":true},{\"relatedFieldId\":\"effective_date\",\"title\":\"Effective\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"DATE\",\"interactive\":true,\"pageFieldId\":\"effectiveDate\",\"isSaveable\":true},{\"relatedFieldId\":\"user_group_id\",\"title\":\"Agency Code\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"agencyCode\",\"isSaveable\":true},{\"relatedFieldId\":\"agency_name\",\""
		"title\":\"Agency Name\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"agencyName\",\"isSaveable\":true},{\"relatedFieldId\":\"underwriter_name\",\"title\":\"Underwriter\",\"selected\":false,\"opCode\":null,\"operands\":[],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":\"underwriterName\",\"isSaveable\":true},{\"relatedFieldId\":\"entity_name\",\"title\":\"Name\",\"selected\":false,\"opCode\":{\"needsTwoOperands\""
		":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"agency_name\",\"title\":\"Agency Name\",\"selected\":false,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"underwriter_name\",\"title\":\"Underwriter\",\"selected\":false,\"opCode\":{\""
		"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"*\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"status\",\"title\":\"Status\",\"selected\":true,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"NOT_EQUAL\"},\"operands\":[\"DELETE\"],\"dataType\":\"STATUS\",\"interactive\":false,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"user_group_id\",\"title\":\"Agency Code\",\"selected\":true,\"opCode\":{"
		"\"needsTwoOperands\":false,\"value\":\"CONTAINS\"},\"operands\":[\"${USERGROUP_IDS}\"],\"dataType\":\"STRING\",\"interactive\":true,\"pageFieldId\":null,\"isSaveable\":false},{\"relatedFieldId\":\"commit_flag\",\"title\":\"Commit Flag\",\"selected\":true,\"opCode\":{\"needsTwoOperands\":false,\"value\":\"EQUALS\"},\"operands\":[\"1\"],\"dataType\":\"INTEGER\",\"interactive\":false,\"pageFieldId\":null,\"isSaveable\":false}],\"transactionId\":\"worklist\",\"pageId\":\"worklistAdvancedSearch\",\""
		"links\":[{\"rel\":\"self\",\"href\":\"/api/worklists/workitems/query_info?view_name=WorkItemsView\",\"parameters\":[\"view_name\"]},{\"rel\":\"operators\",\"href\":\"/api/worklists/workitems/operator_infos\",\"parameters\":[]},{\"rel\":\"dialog-resource\",\"href\":\"/api/products/transactions/worklist/pages/worklistAdvancedSearch\",\"parameters\":[]}]},\"listViews\":[{\"fields\":[{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"ID\",\"id\":\"work_item_id\",\"isDisplayed\""
		":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"Account Id\",\"id\":\"account_id\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Name\",\"id\":\"entity_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Quote Number\",\"id\":\"quote_number\",\"isDisplayed\":true},{\"type\":\"LOB\",\"styleClass\":null,\"format\":null,\"title\":\"LOB\",\"id\":\"lob\",\"isDisplayed\":true},{\""
		"type\":\"DATE\",\"styleClass\":null,\"format\":null,\"title\":\"Effective\",\"id\":\"effective_date\",\"isDisplayed\":true},{\"type\":\"STATUS\",\"styleClass\":null,\"format\":null,\"title\":\"Status\",\"id\":\"status\",\"isDisplayed\":true},{\"type\":\"DECIMAL\",\"styleClass\":null,\"format\":\"currency: ' '\",\"title\":\"Premium\",\"id\":\"premium\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Code\",\"id\":\"user_group_id\",\"isDisplayed\""
		":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Name\",\"id\":\"agency_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter ID\",\"id\":\"underwriter_id\",\"isDisplayed\":false},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter\",\"id\":\"underwriter_name\",\"isDisplayed\":true},{\"type\":\"TIME\",\"styleClass\":null,\"format\":null,\"title\":\"Updated\",\"id\":\""
		"last_update_time\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Transaction Type\",\"id\":\"transaction_type\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":\"percentage\",\"title\":\"Complete %\",\"id\":\"complete_percent\",\"isDisplayed\":false}],\"type\":\"CARD\",\"viewPortSize\":20,\"startRowNumber\":0,\"selected\":true,\"fetchSize\":20},{\"fields\":[{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":"
		"\"ID\",\"id\":\"work_item_id\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":null,\"title\":\"Account Id\",\"id\":\"account_id\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Name\",\"id\":\"entity_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Quote Number\",\"id\":\"quote_number\",\"isDisplayed\":true},{\"type\":\"LOB\",\"styleClass\":null,\"format\":null,\"title\":\"LOB"
		"\",\"id\":\"lob\",\"isDisplayed\":true},{\"type\":\"DATE\",\"styleClass\":null,\"format\":null,\"title\":\"Effective\",\"id\":\"effective_date\",\"isDisplayed\":true},{\"type\":\"STATUS\",\"styleClass\":null,\"format\":null,\"title\":\"Status\",\"id\":\"status\",\"isDisplayed\":true},{\"type\":\"DECIMAL\",\"styleClass\":null,\"format\":\"currency: ' '\",\"title\":\"Premium\",\"id\":\"premium\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Code\","
		"\"id\":\"user_group_id\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Agency Name\",\"id\":\"agency_name\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter ID\",\"id\":\"underwriter_id\",\"isDisplayed\":false},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Underwriter\",\"id\":\"underwriter_name\",\"isDisplayed\":true},{\"type\":\"TIME\",\"styleClass\":null,\"format\":null,\""
		"title\":\"Updated\",\"id\":\"last_update_time\",\"isDisplayed\":true},{\"type\":\"STRING\",\"styleClass\":null,\"format\":null,\"title\":\"Transaction Type\",\"id\":\"transaction_type\",\"isDisplayed\":false},{\"type\":\"INTEGER\",\"styleClass\":null,\"format\":\"percentage\",\"title\":\"Complete %\",\"id\":\"complete_percent\",\"isDisplayed\":false}],\"type\":\"TABULAR\",\"viewPortSize\":40,\"startRowNumber\":0,\"selected\":false,\"fetchSize\":40}],\"savedSearchInfo\":{\"link\":{\"rel\":\"self\","
		"\"href\":\"/api/worklists/workitems/saved_searches?view_name=WorkItemsView\",\"parameters\":[\"saved_search_id\",\"view_name\"]},\"savedSearches\":[],\"currentSearch\":{\"id\":-1,\"name\":null,\"isActive\":true}},\"lookupLinks\":[{\"rel\":\"lookups.basic.STATUS\",\"href\":\"/api/lookups/basic/STATUS\",\"parameters\":null},{\"rel\":\"lookups.basic.ACCOUNT_TYPE\",\"href\":\"/api/lookups/basic/ACCOUNT_TYPE\",\"parameters\":null},{\"rel\":\"lookups.basic.TRANSACTION_TYPE\",\"href\":\"/api/lookups/"
		"basic/TRANSACTION_TYPE\",\"parameters\":null},{\"rel\":\"lookups.basic.LOB\",\"href\":\"/api/lookups/basic/LOB\",\"parameters\":null},{\"rel\":\"lookups.basic.NewWorkItemLink\",\"href\":\"/api/lookups/basic/NewWorkItemLink\",\"parameters\":[\"worklistType\"]}],\"isSaveable\":true}", 
		LAST);
		
	web_url("custom%3Acom.agencyport.api.pojo.OperatorsListBuilder%3AdataType%3DDATE%3A5.0.0.0",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/products/optionlistids/custom%3Acom.agencyport.api.pojo.OperatorsListBuilder%3AdataType%3DDATE%3A5.0.0.0?transaction_id=worklist&field_id=operator&page_id=worklistAdvancedSearch&CSRF_TOKEN={CSRF_TOKEN2}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t21.inf",
		"Mode=HTML",
		LAST);


	web_url("worklist-card.tpl.jsp", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/worklist/partials/worklist-card.tpl.jsp", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("01_WC_02_AgencyPortal",LR_AUTO);

	lr_start_transaction("01_WC_03_WorkersComp");

	web_reg_find("Text=agencyportal", 
		LAST);

/*Correlation comment - Do not change!  Original value='6539' Name ='WORKITEMID' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=WORKITEMID",
		"LB=name=\"WORKITEMID\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='1ae93bb5803ac6c05c3dec29dad64433371fe16c26e1c7ee3f27481c1b07a29e' Name ='CSRF_TOKEN5' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN5",
		"RegExp=CSRF_TOKEN=(.*?)\\\r\\\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='22403c5ce7168258cc277733b97e1de5350a4e970e03594ca4b59cc4fcf9e44e' Name ='CSRF_TOKEN6' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=CSRF_TOKEN6",
		"LB='CSRF_TOKEN': '",
		"RB='",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=cAgencyName",
		"RegExp=\"value\":\"(.*?)\",",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=BODY",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

web_reg_save_param_regexp(
		"ParamName=rnd1",
		"RegExp=rnd=(.*?)&CSRF_TOKEN",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

		
   web_reg_save_param_regexp(
	"ParamName=cApplicantLegalEntity",
		"RegExp=<option value=\"(.+?)\">",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=BODY",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);
 
  
	web_url("FrontServlet",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&FIRST_TIME=true&METHOD=Display&rnd={rnd}&CSRF_TOKEN={CSRF_TOKEN}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/DisplayWorkInProgress?WorkListType=WorkItemsView",
		"Snapshot=t24.inf",
		"Mode=HTML",
		LAST);

  count2=rand()%17+107;
  arr3=lr_paramarr_idx("cApplicantLegalEntity",count2);
  lr_save_string(arr3,"cApplicantLegalEntity1");
	

	web_submit_data("FileUploadServlet_2",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}CSRF_TOKEN={CSRF_TOKEN5}",
		"Snapshot=t25.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=requestType", "Value=list", ENDITEM,
		LAST);

web_reg_save_param_regexp(
      "ParamName=cControllingState",
      "RegExp=field.addListOption\\(\"(.+?)\",\\ \"(.+?)\",",
		"Group=2",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
  
	web_custom_request("IntrapageDTRServlet",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/plain",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}",
		"Mode=HTML",
		"EncType=text/xml",
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\"/><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\"/><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueI"
		"d=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldEleme"
		"nt uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\"/><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"4\" pos=\"31\"/><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"4\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"4\" pos=\"33\"/><fieldElement uniqueId=\"AgencyState\""
		" interestLevel=\"4\" pos=\"34\"/><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"4\" pos=\"35\"/><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"4\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"4\" pos=\"37\"/><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"4\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\"/><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\"/><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"ExtendedNamed"
		"Insureds\" interestLevel=\"2\" pos=\"9\">false</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"2\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"2\" pos=\"11\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"2\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"2\" pos=\"13\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"2\" pos=\"14\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"2\" pos=\"15\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" "
		"interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\"/><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" pos=\"27\"/><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestL"
		"evel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\" pos=\"34\"/><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">FEIN</fieldElement><fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isHot=\"true\"/><fieldElement uniqueId=\"PrimaryBusDescription\" interestLevel=\"2\" pos=\"1\" isHot=\"true\"/><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"P"
		"rogramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>",
		LAST);


  


	

	web_url("data",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN6}&rnd=1513767818031&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}",
		"Snapshot=t27.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("01_WC_03_WorkersComp",LR_AUTO);

		

	lr_start_transaction("01_WC_04_GeneralInformation");
	
do
{
	 do
   {
 	arr=lr_paramarr_random("cAgencyName");
      lr_save_string(arr,"newAgencyName");
     }while(atoi((lr_eval_string("{newAgencyName}")))==0);

web_convert_param("cAgencyName1","SourceString={newAgencyName}", "SourceEncoding=HTML", "TargetEncoding=PLAIN", LAST );

   token=(char *)strtok(lr_eval_string("{cAgencyName1}"),"/");
   lr_save_string(token,"value1");
   
   
   token=(char *)strtok(NULL,"/");
   
   lr_save_string(token,"value2");
   
   lr_output_message("the value:%s",token);

     web_reg_save_param_regexp(
      "ParamName=cProducerName",
      "RegExp=field.addListOption\\(\"(.*?)\",\\ \"(.*?)\",",
		"Group=2",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);

	


	web_custom_request("IntrapageDTRServlet_2",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}",
		"Mode=HTML",
		"EncType=text/xml",
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\" interestLevel=\"2\" pos=\"11\">N"
		"</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interes"
		"tLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isOrigin=\"true\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\"/><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"4\" pos=\"31\"/><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"4\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" intere"
		"stLevel=\"4\" pos=\"33\"/><fieldElement uniqueId=\"AgencyState\" interestLevel=\"4\" pos=\"34\"/><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"4\" pos=\"35\"/><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"4\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"4\" pos=\"37\"/><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"4\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\"/><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\"/><fieldElement uniqueId=\"DoingBusinessAs\" inter"
		"estLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">false</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\""
		"19\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\"/><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" pos=\"27\"/><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2"
		"\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\" pos=\"34\"/><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">FEIN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" interestLevel=\"2\" pos=\"1\" isHot=\"true\"/><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueI"
		"d=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>",
		LAST);
	
  }while(atoi(lr_eval_string("{cProducerName_count}"))==2);
  
            do
           {
           	   arr1=lr_paramarr_random("cProducerName");
                lr_save_string(arr1,"newProdName");
               
            }while((atoi(lr_eval_string("{newProdName}"))==0)  || "newProdName"=="NL&#47;&#47;&#47;");
 
  
     web_convert_param("cProdName1","SourceString={newProdName}", "SourceEncoding=HTML", "TargetEncoding=PLAIN", LAST );
     
  //r_thinkk_time(10);
	
	web_custom_request("IntrapageDTRServlet_3",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}",
		"Mode=HTML",
		"EncType=text/xml",
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\" interestLevel=\"2\" pos=\"11\">N"
		"</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interes"
		"tLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\"/><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"4\" pos=\"31\"/><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"4\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLeve"
		"l=\"4\" pos=\"33\"/><fieldElement uniqueId=\"AgencyState\" interestLevel=\"4\" pos=\"34\"/><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"4\" pos=\"35\"/><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"4\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"4\" pos=\"37\"/><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"4\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\"/><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\"/><fieldElement uniqueId=\"DoingBusinessAs\" interestLev"
		"el=\"2\" pos=\"8\"/><fieldElement uniqueId=\"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">false</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\"/>"
		"<fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\"/><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" pos=\"27\"/><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos"
		"=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\" pos=\"34\"/><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">FEIN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isOrigin=\"true\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" interestLevel=\"2\" pos=\"1\" isHot=\"true\"/><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldEle"
		"ment uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><analyticsFieldData uniqueId=\"AgencyProducer\"><attribute name=\"isPendingIPDTR\">true</attribute><attribute name=\"analyticsFieldValue\"/></analyticsFieldData><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>",
		LAST);

	

	

	web_reg_save_param_regexp(
      "ParamName=cAgencyAddr",
      "RegExp=field.setValue\\(\"(.*)?\"",
      "Ordinal=4",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);

	web_reg_save_param_regexp(
      "ParamName=cAgencyCity",
      "RegExp=field.setValue\\(\"(.*)?\"",
      "Ordinal=6",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
	
web_reg_save_param_regexp(
      "ParamName=cAgencyState",
      "RegExp=field.setValue\\(\"(.*)?\"",
      "Ordinal=7",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);

web_reg_save_param_regexp(
      "ParamName=cAgencyZip",
      "RegExp=field.setValue\\(\"(.*)?\"",
      "Ordinal=8",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
    
   
	web_custom_request("IntrapageDTRServlet_4",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/plain",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}",
		"Mode=HTML",
		"EncType=text/xml",
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\" interestLevel=\"2\" pos=\"11\">N"
		"</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interes"
		"tLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isOrigin=\"true\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"4\" pos=\"31\"/><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"4\" pos="
		"\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"4\" pos=\"33\"/><fieldElement uniqueId=\"AgencyState\" interestLevel=\"4\" pos=\"34\"/><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"4\" pos=\"35\"/><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"4\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"4\" pos=\"37\"/><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"4\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\"/><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true"
		"\"/><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">false</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"Applica"
		"ntMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\"/><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" pos=\"27\"/><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldE"
		"lement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\" pos=\"34\"/><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">FEIN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" interestLevel=\"2\" pos=\"1\" isHot=\"true\"/><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel="
		"\"4\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>",
		LAST);


	web_reg_save_param_regexp(
		"ParamName=cPrimaryBus",
		"RegExp=field.addListOption\\(\"(.*?)\",\\ \"(.*?)\",",
		"Group=2",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=BODY",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);

	web_custom_request("IntrapageDTRServlet_5", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}",
		"Mode=HTML",
	    "EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isOrigin=\"true\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" "
		"interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\"/><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">false</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement>"
		"<fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\"/><fieldElement "
		"uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\""
		"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\"/><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\""
		" pos=\"27\"/><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\" pos=\"34\"/><fieldElement uniqueId=\""
		"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">FEIN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" interestLevel=\"2\" pos=\"1\" isHot=\"true\"/><fieldElement "
		"uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\""
		"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</"
		"target></intraPageDTRRequest>", 
		LAST);
     
     do
     {
     	arr2=lr_paramarr_random("cPrimaryBus");
     	lr_save_string(arr2,"cPrimaryBus1");
     }while((atoi(lr_eval_string("{cPrimaryBus1}")))==0);
    
 
	
	web_custom_request("IntrapageDTRServlet_6", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}",
		"Mode=HTML",
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"4\""
		" pos=\"4\">false</fieldElement><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">{ExpirationDate}</fieldElement><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\"/><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">false</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\""
		" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15"
		"\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\"/>"
		"<fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\"/><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\""
		"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" pos=\"27\"/><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity"
		"\" interestLevel=\"2\" pos=\"34\"/><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">FEIN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" "
		"interestLevel=\"2\" pos=\"1\" isHot=\"true\"/><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel"
		"=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><analyticsFieldData uniqueId=\"PMA\"><attribute name=\""
		"isPendingIPDTR\">true</attribute><attribute name=\"analyticsFieldValue\">Contractor</attribute></analyticsFieldData><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

web_custom_request("IntrapageDTRServlet_7", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"4\""
		" pos=\"4\">false</fieldElement><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">{ExpirationDate}</fieldElement><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\"/><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">false</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\""
		">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true"
		"\"/><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\"/><fieldElement "
		"uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\"/><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" "
		"interestLevel=\"2\" pos=\"27\"/><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\" pos=\"34\"/>"
		"<fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">FEIN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isOrigin=\"true\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" interestLevel=\"2"
		"\" pos=\"1\" isHot=\"true\"/><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/"
		"><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><analyticsFieldData uniqueId=\"PMA\"><attribute name=\"isPendingIPDTR\">true</"
		"attribute><attribute name=\"analyticsFieldValue\">Contractor</attribute></analyticsFieldData><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	
	web_reg_save_param_regexp(
		"ParamName=cApplicantZip",
		"RegExp=ApplicantMailingZip_US&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);

     	web_reg_save_param_regexp(
		"ParamName=cApplicantLatitude",
		"RegExp=ApplicantMailingGEOLatitude&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantCity",
		"RegExp=ApplicantMailingCity&quot;:&quot;(.*?)&quot",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantService",
		"RegExp=ServiceMessage&quot;:&quot;(.*?)&quot",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantMailingAddress",
		"RegExp=ApplicantMailingAddress1&quot;:&quot;(.*?)&quot",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantState",
		"RegExp=ApplicantMailingState&quot;:&quot;(.*?)&quot;,&",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantPlaceCd",
		"RegExp=ApplicantMailingGEOPlaceCd&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantCountryName",
		"RegExp=ApplicantMailingGEOCountyName&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantCensusBlock",
		"RegExp=ApplicantMailingGEOCensusBlock&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantLongitude",
		"RegExp=ApplicantMailingGEOLongitude&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantCountryFIPS",
		"RegExp=ApplicantMailingGEOCountyFIPS&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
		"ParamName=cApplicantCensusTract",
		"RegExp=ApplicantMailingGEOCensusTract&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
      web_reg_save_param_regexp(
		"ParamName=cApplicantGEOSubDivCode",
		"RegExp=ApplicantMailingGEOSubdivisionCode&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     
     
	web_custom_request("IntrapageDTRServlet_8", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"4\""
		" pos=\"4\">false</fieldElement><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">{ExpirationDate}</fieldElement><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\">{ApplicantName}</fieldElement><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">true</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\""
		"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\">{Address1}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot=\"true\">{City}</fieldElement><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\">{State}</"
		"fieldElement><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isOrigin=\"true\" isHot=\"true\">{Zip}</fieldElement><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\""
		"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\"/"
		"><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" pos=\"27\"/><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\""
		"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\" pos=\"34\"/><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">FEIN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" "
		"interestLevel=\"4\" pos=\"0\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" interestLevel=\"2\" pos=\"1\" isHot=\"true\"/><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldElement "
		"uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/>"
		"<fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
     
   

	web_custom_request("IntrapageDTRServlet_9", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\""
		"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"4\" pos=\"4\">false</fieldElement><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">{ExpirationDate}</fieldElement><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\">{ApplicantName}</fieldElement><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\""
		"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">true</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\">{cApplicantMailingAddress}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot"
		"=\"true\">{cApplicantCity}</fieldElement><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\">{cApplicantState}</fieldElement><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\">{cApplicantPlaceCd}</"
		"fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\">{cApplicantCensusTract}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\">{cApplicantCensusBlock}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\">{cApplicantCountryFIPS}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\">{cApplicantLatitude}</fieldElement><fieldElement uniqueId=\""
		"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\">{cApplicantLongitude}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\">GS01</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\">{cApplicantCountryName}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\">{cApplicantGEOSubDivCode}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" "
		"pos=\"27\">EXACTMATCH</fieldElement><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\"/><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\" pos=\"34\"/>"
		"<fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">SSN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"37\"/>{SSN}<fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isOrigin=\"true\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" interestLevel=\"2"
		"\" pos=\"1\" isHot=\"true\"/><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/"
		"><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target"
		">WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

     web_reg_save_param_regexp(
      "ParamName=cMarketSegment",
      "RegExp=field.setValue\\(\"(.*)?\"",
      "Ordinal=7",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
      "ParamName=cSICCode",
      "RegExp=field.setValue\\(\"(.*)?\"",
      "Ordinal=8",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
      "ParamName=cNAICSCode",
      "RegExp=field.setValue\\(\"(.*)?\"",
      "Ordinal=9",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
      "ParamName=cUnderWriterId",
      "RegExp=field.addListOption\\(\"(.*?)\",\\ \"(.*?)\",",
		"Group=2",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=ALL",
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);

     
     
	web_custom_request("IntrapageDTRServlet_10", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\""
		"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"4\" pos=\"4\">false</fieldElement><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">{ExpirationDate}</fieldElement><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\">{ApplicantName}</fieldElement><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\""
		"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">true</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\">{cApplicantMailingAddress}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot"
		"=\"true\">{cApplicantCity}</fieldElement><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\">{cApplicantState}</fieldElement><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\">{cApplicantZip}</fieldElement><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\">{cApplicantPlaceCd}</"
		"fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\">{cApplicantCensusTract}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\">{cApplicantCensusBlock}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\">{cApplicantCountryFIPS}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\">{cApplicantLatitude}</fieldElement><fieldElement uniqueId=\""
		"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\">{cApplicantLongitude}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\">GS01</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\">{cApplicantCountryName}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\">{cApplicantGEOSubDivCode}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" "
		"pos=\"27\">EXACTMATCH</fieldElement><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\">2</fieldElement><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\""
		" pos=\"34\">{cApplicantLegalEntity1}</fieldElement><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">SSN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"37\"/>{SSN}<fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" "
		"interestLevel=\"2\" pos=\"1\" isOrigin=\"true\" isHot=\"true\">{cPrimaryBus1}</fieldElement><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2\" pos=\"6\"/><fieldElement "
		"uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\"/><page compoundKey="
		"\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

     //r_thinkk_time(2);
     
	web_custom_request("IntrapageDTRServlet_11", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\""
		"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"4\" pos=\"4\">false</fieldElement><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">{ExpirationDate}</fieldElement><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\">{ApplicantName}</fieldElement><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\""
		"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">true</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\">{cApplicantMailingAddress}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot"
		"=\"true\">{cApplicantCity}</fieldElement><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\">{cApplicantState}</fieldElement><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\">{cApplicantZip}</fieldElement><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\">{cApplicantPlaceCd}</"
		"fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\">{cApplicantCensusTract}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\">{cApplicantCensusBlock}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\">{cApplicantCountryFIPS}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\">{cApplicantLatitude}</fieldElement><fieldElement uniqueId=\""
		"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\">{cApplicantLongitude}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\">GS01</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\">{cApplicantCountryName}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\">{cApplicantGEOSubDivCode}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" "
		"pos=\"27\">EXACTMATCH</fieldElement><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\">2</fieldElement><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\""
		" pos=\"34\">{cApplicantLegalEntity1}</fieldElement><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">SSN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"37\"/>{SSN}<fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isOrigin=\"true\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\""
		"PrimaryBusDescription\" interestLevel=\"2\" pos=\"1\" isHot=\"true\">{cPrimaryBus1}</fieldElement><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\">{cMarketSegment}</fieldElement><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\">{cSICCode}</fieldElement><fieldElement uniqueId=\"ApplicantNAICSCode\" "
		"interestLevel=\"2\" pos=\"6\">{cNAICSCode}</fieldElement><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"Applicant3OrMoreFullTimeEmployee\" interestLevel=\"2\" pos=\"0\"/>"
		"<fieldElement uniqueId=\"OperationOfHazardousMaterial\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"WorkBlastingDemolitionSandblastingWrecking\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkPetrochemicalNuclearOilPowerPlant\" interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\"WorkBargesVesselsDocksBridge\" interestLevel=\"2\" pos=\"5\"/><fieldElement uniqueId=\"ShoringTrenchBoxes5ftDeep\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"LossPast3Years\" "
		"interestLevel=\"4\" pos=\"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\">{cUnderWriterId}</fieldElement><analyticsFieldData uniqueId=\"MarketSegment\"><attribute name=\"isPendingIPDTR\">true</attribute><attribute name=\"analyticsFieldValue\"/></analyticsFieldData><analyticsFieldData uniqueId=\"ApplicantSICCode\"><attribute name=\"isPendingIPDTR\">true</attribute><attribute name=\"analyticsFieldValue\"/></analyticsFieldData><page compoundKey=\"workersComp/generalInfo\" isRoster="
		"\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
     
     //r_thinkk_time(2);
     
	web_custom_request("IntrapageDTRServlet_12", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\""
		"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"4\" pos=\"4\">false</fieldElement><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">{ExpirationDate}</fieldElement><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\">{ApplicantName}</fieldElement><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\""
		"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">true</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\">{cApplicantMailingAddress}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot"
		"=\"true\">{cApplicantCity}</fieldElement><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\">{cApplicantState}</fieldElement><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\">{cApplicantZip}</fieldElement><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\">{cApplicantPlaceCd}</"
		"fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\">{cApplicantCensusTract}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\">{cApplicantCensusBlock}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\">{cApplicantCountryFIPS}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\">{cApplicantLatitude}</fieldElement><fieldElement uniqueId=\""
		"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\">{cApplicantLongitude}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\">GS01</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\">{cApplicantCountryName}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\">{cApplicantGEOSubDivCode}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" "
		"pos=\"27\">EXACTMATCH</fieldElement><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\">2</fieldElement><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\""
		" pos=\"34\">{cApplicantLegalEntity1}</fieldElement><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">SSN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"37\"/>{SSN}<fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" "
		"interestLevel=\"2\" pos=\"1\" isHot=\"true\">{cPrimaryBus1}</fieldElement><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isOrigin=\"true\" isHot=\"true\">{cMarketSegment}</fieldElement><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isHot=\"true\">{cSICCode}</fieldElement><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2"
		"\" pos=\"6\">{cNAICSCode}</fieldElement><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"Applicant3OrMoreFullTimeEmployee\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId="
		"\"OperationOfHazardousMaterial\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"WorkBlastingDemolitionSandblastingWrecking\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkPetrochemicalNuclearOilPowerPlant\" interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\"WorkBargesVesselsDocksBridge\" interestLevel=\"2\" pos=\"5\"/><fieldElement uniqueId=\"ShoringTrenchBoxes5ftDeep\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\""
		"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\">{cUnderWriterId}</fieldElement><analyticsFieldData uniqueId=\"ApplicantSICCode\"><attribute name=\"isPendingIPDTR\">true</attribute><attribute name=\"analyticsFieldValue\"/></analyticsFieldData><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

     
          //r_thinkk_time(2);
          
	web_custom_request("IntrapageDTRServlet_13", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"SecuraCommlPolicyLOBCd\" interestLevel=\"4\" pos=\"0\">WORK</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessLOBCd\" interestLevel=\"4\" pos=\"2\">WORK</fieldElement><fieldElement uniqueId=\"SecuraCommlPolicyId\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\"WorkCompLineBusinessId\" interestLevel=\"2\" pos=\"5\">GUID()</fieldElement><fieldElement uniqueId=\""
		"GenInfoTransactionRequestDt\" interestLevel=\"2\" pos=\"6\">SYSTEM_DATE()</fieldElement><fieldElement uniqueId=\"RqUID\" interestLevel=\"2\" pos=\"7\">GUID()</fieldElement><fieldElement uniqueId=\"CurCd\" interestLevel=\"2\" pos=\"8\">USD</fieldElement><fieldElement uniqueId=\"AccClearanceFieldForIPDTR\" interestLevel=\"2\" pos=\"9\" isHot=\"true\">NO</fieldElement><fieldElement uniqueId=\"AccClearanceMultiResultJSON\" interestLevel=\"2\" pos=\"10\"/><fieldElement uniqueId=\"CreateNewAccountFlag\""
		" interestLevel=\"2\" pos=\"11\">N</fieldElement><fieldElement uniqueId=\"SPAGCODE\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"SPAGNAME\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"SPACCOUNTNO\" interestLevel=\"2\" pos=\"14\"/><fieldElement uniqueId=\"SPCUSTNAME\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"SPDBA\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"SPADD\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"SPPHONE\" "
		"interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"SPFEIN\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"SPDATE\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"SPPKG\" interestLevel=\"2\" pos=\"21\"/><fieldElement uniqueId=\"SPAUTO\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"SPWC\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"SPUM\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"hiddenClearanceOverride\" interestLevel=\"2\" pos=\""
		"25\">NO</fieldElement><fieldElement uniqueId=\"ShowFlag\" interestLevel=\"2\" pos=\"26\"/><fieldElement uniqueId=\"SPClearnceInputChangeFlag\" interestLevel=\"2\" pos=\"27\">N</fieldElement><fieldElement uniqueId=\"AgencyName\" interestLevel=\"2\" pos=\"28\" isHot=\"true\">{cAgencyName1}</fieldElement><fieldElement uniqueId=\"N382\" interestLevel=\"2\" pos=\"29\">If the producer is not shown in the list below, please select the &apos;Not Listed&apos; option.  A listed producer is "
		"required to issue a policy.  To add a producer, please complete the agent appointment applicant here: &lt;a href=&quot;https://agentlink.secura.net/agent_appointment_app.html&quot; target=&quot;_blank&quot;&gt; https://agentlink.secura.net/agent_appointment_app.html&lt;/a&gt;</fieldElement><fieldElement uniqueId=\"AgencyProducer\" interestLevel=\"2\" pos=\"30\" isHot=\"true\">{cProdName1}</fieldElement><fieldElement uniqueId=\"AgencyAddr1\" interestLevel=\"2\" pos=\"31\">{cAgencyAddr}</fieldElement><fieldElement uniqueId=\"AgencyAddr2\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"AgencyCity\" interestLevel=\"2\" pos=\"33\">{cAgencyCity}</fieldElement><fieldElement uniqueId=\"AgencyState\" interestLevel=\"2\" pos=\"34\">{cAgencyState}</fieldElement><fieldElement uniqueId=\"AgencyZip\" interestLevel=\"2\" pos=\"35\">{cAgencyZip}</fieldElement><fieldElement uniqueId=\"AgencyPhone\" interestLevel=\"2\" pos=\"36\"/><fieldElement uniqueId=\"AgentCSRPhone\" interestLevel=\"2\" pos=\"37\"/"
		"><fieldElement uniqueId=\"AgencyEmail\" interestLevel=\"2\" pos=\"38\"/><fieldElement uniqueId=\"GenInfoAddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMessage\" interestLevel=\"2\" pos=\"1\">Address has been updated and standardized, please continue.</fieldElement><fieldElement uniqueId=\"GenInfoMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\""
		"EffectiveDate\" interestLevel=\"2\" pos=\"3\" isHot=\"true\">{EffectiveDate}</fieldElement><fieldElement uniqueId=\"EffectiveDateUWOR\" interestLevel=\"4\" pos=\"4\">false</fieldElement><fieldElement uniqueId=\"ExpirationDate\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">{ExpirationDate}</fieldElement><fieldElement uniqueId=\"ApplicantName\" interestLevel=\"2\" pos=\"7\" isHot=\"true\">{ApplicantName}</fieldElement><fieldElement uniqueId=\"DoingBusinessAs\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\""
		"ExtendedNamedInsureds\" interestLevel=\"2\" pos=\"9\">true</fieldElement><fieldElement uniqueId=\"ApplicantMailingCountry\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">USA</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress1\" interestLevel=\"4\" pos=\"11\" isHot=\"true\">{cApplicantMailingAddress}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddress2\" interestLevel=\"4\" pos=\"12\" isHot=\"true\"/><fieldElement uniqueId=\"ApplicantMailingCity\" interestLevel=\"4\" pos=\"13\" isHot"
		"=\"true\">{cApplicantCity}</fieldElement><fieldElement uniqueId=\"ApplicantMailingState\" interestLevel=\"4\" pos=\"14\" isHot=\"true\">{cApplicantState}</fieldElement><fieldElement uniqueId=\"ApplicantMailingZip_US\" interestLevel=\"4\" pos=\"15\" isHot=\"true\">{cApplicantZip}</fieldElement><fieldElement uniqueId=\"ApplicantMailingKeepAddressasEntered\" interestLevel=\"2\" pos=\"16\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOPlaceCd\" interestLevel=\"2\" pos=\"18\">{cApplicantPlaceCd}</"
		"fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusTract\" interestLevel=\"2\" pos=\"19\">{cApplicantCensusTract}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCensusBlock\" interestLevel=\"2\" pos=\"20\">{cApplicantCensusBlock}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyFIPS\" interestLevel=\"2\" pos=\"21\">{cApplicantCountryFIPS}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOLatitude\" interestLevel=\"2\" pos=\"22\">{cApplicantLatitude}</fieldElement><fieldElement uniqueId=\""
		"ApplicantMailingGEOLongitude\" interestLevel=\"2\" pos=\"23\">{cApplicantLongitude}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOResult\" interestLevel=\"2\" pos=\"24\">GS01</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOCountyName\" interestLevel=\"2\" pos=\"25\">{cApplicantCountryName}</fieldElement><fieldElement uniqueId=\"ApplicantMailingGEOSubdivisionCode\" interestLevel=\"2\" pos=\"26\">{cApplicantGEOSubDivCode}</fieldElement><fieldElement uniqueId=\"ApplicantMailingAddressValidationFlag\" interestLevel=\"2\" "
		"pos=\"27\">EXACTMATCH</fieldElement><fieldElement uniqueId=\"ApplicantPhone\" interestLevel=\"2\" pos=\"28\"/><fieldElement uniqueId=\"ApplicantYearsBusiness\" interestLevel=\"2\" pos=\"29\">2</fieldElement><fieldElement uniqueId=\"NamedInsuredExternalId\" interestLevel=\"2\" pos=\"31\"/><fieldElement uniqueId=\"WebsiteAddress\" interestLevel=\"2\" pos=\"32\"/><fieldElement uniqueId=\"EMailAddress\" interestLevel=\"2\" pos=\"33\"/><fieldElement uniqueId=\"ApplicantLegalEntity\" interestLevel=\"2\""
		" pos=\"34\">{cApplicantLegalEntity1}</fieldElement><fieldElement uniqueId=\"TaxIdType\" interestLevel=\"2\" pos=\"35\" isHot=\"true\">SSN</fieldElement><fieldElement uniqueId=\"TaxIdFEIN\" interestLevel=\"2\" pos=\"37\"/>{SSN}<fieldElement uniqueId=\"NCCIId\" interestLevel=\"2\" pos=\"39\"/><fieldElement uniqueId=\"StateEmployerNumber\" interestLevel=\"2\" pos=\"40\"/><fieldElement uniqueId=\"PMA\" interestLevel=\"4\" pos=\"0\" isHot=\"true\">Contractor</fieldElement><fieldElement uniqueId=\"PrimaryBusDescription\" "
		"interestLevel=\"2\" pos=\"1\" isHot=\"true\">{cPrimaryBus1}</fieldElement><fieldElement uniqueId=\"HazardGrade\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"NatureofBusiness\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MarketSegment\" interestLevel=\"2\" pos=\"4\" isHot=\"true\">{cMarketSegment}</fieldElement><fieldElement uniqueId=\"ApplicantSICCode\" interestLevel=\"4\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">{cSICCode}</fieldElement><fieldElement uniqueId=\"ApplicantNAICSCode\" interestLevel=\"2"
		"\" pos=\"6\">{cNAICSCode}</fieldElement><fieldElement uniqueId=\"ControllingState\" interestLevel=\"4\" pos=\"7\"/><fieldElement uniqueId=\"ProgramAssociation\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"Applicant3OrMoreFullTimeEmployee\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId="
		"\"OperationOfHazardousMaterial\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"WorkBlastingDemolitionSandblastingWrecking\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkPetrochemicalNuclearOilPowerPlant\" interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\"WorkBargesVesselsDocksBridge\" interestLevel=\"2\" pos=\"5\"/><fieldElement uniqueId=\"ShoringTrenchBoxes5ftDeep\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"LossPast3Years\" interestLevel=\"4\" pos=\""
		"10\"/><fieldElement uniqueId=\"Underwriter\" interestLevel=\"2\" pos=\"0\">{cUnderWriterId}</fieldElement><analyticsFieldData uniqueId=\"PMA\"><attribute name=\"isPendingIPDTR\">true</attribute><attribute name=\"analyticsFieldValue\">Contractor</attribute></analyticsFieldData><page compoundKey=\"workersComp/generalInfo\" isRoster=\"false\"/><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	
     lr_output_message("the state :%s",lr_eval_string("{State}"));
    
    do
    {
        		
  arr2=lr_paramarr_random("cControllingState");
  lr_save_string(arr2,"cControllingState1");
    }while(strcmp("cControllingState1", lr_eval_string("{State}")) == 0);
    
    
/*Correlation comment - Do not change!  Original value='9a52419dd4cf1c3fc3c4140d1ed6fa9c116e29a50182f1db8af791da14954b1c' Name ='CSRF_TOKEN7' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN7",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='1474661210' Name ='HASH' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);
		

	web_submit_data("FrontServlet_16",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=generalInfo&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&METHOD=Display&TRANSACTIONSTARTPOINT=true&rnd={rnd1}&CSRF_TOKEN={CSRF_TOKEN5}",
		"Snapshot=t42.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=0", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=generalInfo", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN6}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=SecuraCommlPolicyLOBCd", "Value=WORK", ENDITEM,
		"Name=WorkCompLineBusinessLOBCd", "Value=WORK", ENDITEM,
		"Name=SecuraCommlPolicyId", "Value=GUID()", ENDITEM,
		"Name=WorkCompLineBusinessId", "Value=GUID()", ENDITEM,
		"Name=GenInfoTransactionRequestDt", "Value=SYSTEM_DATE()", ENDITEM,
		"Name=RqUID", "Value=GUID()", ENDITEM,
		"Name=CurCd", "Value=USD", ENDITEM,
		"Name=AccClearanceFieldForIPDTR", "Value=NO", ENDITEM,
		"Name=AccClearanceMultiResultJSON", "Value=\\{\"body\":[[{\"type\":\"TEXT\",\"value\":\"{value1}\",\"titleRow\":true},\\{\"type\":\"TEXT\",\"value\":\"{value2}\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"{ApplicantName}\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"{cApplicantMailingAddress}  {cApplicantCity},{cApplicantState},{cApplicantZip}\",\"titleRow\":true},\\{\"type\":\"TEXT\",\"value\":\"\",\"titleRow\":true},\\{\"type\":\"TEXT\",\"value\":\"***-**-9999\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"\",\"titleRow\":true},{\"type\":\"TEXT\",\"value\":\"\",\"titleRow\":true}]],\"buttons\":[{\"rank\":\"primary\",\"value\":\"Save\",\"onclick\":\"saveAccountSearchData\",\"type\":\"save\"}],\"header\":[{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Agency Code\",\"uniqueId\":\"SPAGCODE\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Agency Name\",\"uniqueId\":\"SPAGNAME\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Account Number\",\"uniqueId\":\"SPACCOUNTNO\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Customer Name\",\"uniqueId\":\"SPCUSTNAME\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"DBA\",\"uniqueId\":\"SPDBA\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Address\",\"uniqueId\":\"SPFEIN\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Phone\",\"uniqueId\":\"SPPHONE\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"FEIN/SSN\",\"uniqueId\":\"SPFEIN\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Submitted Date\",\"uniqueId\":\"SPDATE\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Package\",\"uniqueId\":\"SPPKG\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Auto\",\"uniqueId\":\"SPAUTO\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"WC\",\"uniqueId\":\"SPWC\"},{\"data_alignment\":\"left\",\"filterable\":false,\"hidden\":false,\"sortable\":false,\"width\":\"50px\",\"label\":\"Umbrella\",\"uniqueId\":\"SPUM\"}],\"general\":{\"title\":\"Account Clearance\",\"show_filters\":false,\"selectable\":true,\"supports_sorting\":true,\"allow_nonstandard_close\":true,\"event_field_id\":\"fieldId\",\"emptyTo\":\"top\",\"supports_filtering\":false,\"remove_x_close\":true,\"auto_save\":true},\"addressErrorMessage\":[],\"messageCode\":\"NOMATCH\",\"insideAgencyCount\":0,\"outsideAgencyCount\":0,\"errorCode\":\"\"}", ENDITEM,
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
		"Name=ShowFlag", "Value=NOMATCH", ENDITEM,
		"Name=SPClearnceInputChangeFlag", "Value=N", ENDITEM,
		"Name=AgencyName", "Value={cAgencyName1}", ENDITEM,
		"Name=AgencyProducer", "Value={cProdName1}", ENDITEM,
		"Name=AgencyAddr1", "Value={cAgencyAddr}", ENDITEM,
		"Name=AgencyAddr2", "Value=", ENDITEM,
		"Name=AgencyCity", "Value={cAgencyCity}", ENDITEM,
		"Name=AgencyState", "Value={cAgencyState}", ENDITEM,
		"Name=AgencyZip", "Value={cAgencyZip}", ENDITEM,
		"Name=AgentCSRPhone", "Value=", ENDITEM,
		"Name=AgencyPhone", "Value=", ENDITEM,
		"Name=AgencyEmail", "Value=", ENDITEM,
		"Name=GenInfoMessage", "Value=Address has been updated and standardized, please continue.", ENDITEM,
		"Name=GenInfoMultiResultJSON", "Value=", ENDITEM,
		"Name=EffectiveDate", "Value={EffectiveDate}", ENDITEM,
		"Name=EffectiveDateUWOR", "Value=false", ENDITEM,
		"Name=ExpirationDate", "Value={ExpirationDate}", ENDITEM,
		"Name=ApplicantName", "Value={ApplicantName}", ENDITEM,
		"Name=DoingBusinessAs", "Value=Regression & CO", ENDITEM,
		"Name=ExtendedNamedInsureds", "Value=true", ENDITEM,
		"Name=ApplicantMailingCountry", "Value=USA", ENDITEM,
		"Name=ApplicantMailingAddress1", "Value={cApplicantMailingAddress}", ENDITEM,
		"Name=ApplicantMailingAddress2", "Value=", ENDITEM,
		"Name=ApplicantMailingCity", "Value={cApplicantCity}", ENDITEM,
		"Name=ApplicantMailingState", "Value={cApplicantState}", ENDITEM,
		"Name=ApplicantMailingZip_US", "Value={cApplicantZip}", ENDITEM,
	//	"Name=ApplicantMailingKeepAddressasEntered", "Value=1", ENDITEM,
		"Name=ApplicantMailingGEOPlaceCd", "Value={cApplicantPlaceCd}", ENDITEM,
		"Name=ApplicantMailingGEOCensusTract", "Value={cApplicantCensusTract}", ENDITEM,
		"Name=ApplicantMailingGEOCensusBlock", "Value={cApplicantCensusBlock}", ENDITEM,
		"Name=ApplicantMailingGEOCountyFIPS", "Value={cApplicantCountryFIPS}", ENDITEM,
		"Name=ApplicantMailingGEOLatitude", "Value={cApplicantLatitude}", ENDITEM,
		"Name=ApplicantMailingGEOLongitude", "Value={cApplicantLongitude}", ENDITEM,
		"Name=ApplicantMailingGEOResult", "Value=GS01", ENDITEM,
		"Name=ApplicantMailingGEOCountyName", "Value={cApplicantCountryName}", ENDITEM,
		"Name=ApplicantMailingGEOSubdivisionCode", "Value={cApplicantGEOSubDivCode}", ENDITEM,
		"Name=ApplicantMailingAddressValidationFlag", "Value=EXACTMATCH", ENDITEM,
		"Name=ApplicantPhone", "Value=", ENDITEM,
		"Name=ApplicantYearsBusiness", "Value=2", ENDITEM,
		"Name=NamedInsuredExternalId", "Value=", ENDITEM,
		"Name=WebsiteAddress", "Value=", ENDITEM,
		"Name=EMailAddress", "Value=", ENDITEM,
		"Name=ApplicantLegalEntity", "Value={cApplicantLegalEntity1}", ENDITEM,
		"Name=TaxIdType", "Value=SSN", ENDITEM,
		"Name=TaxIdSSN", "Value={SSN}", ENDITEM,
		"Name=NCCIId", "Value=", ENDITEM,
		"Name=StateEmployerNumber", "Value=", ENDITEM,
		"Name=PMA", "Value=Industrial/Processing", ENDITEM,
		"Name=PrimaryBusDescription", "Value={cPrimaryBus1}", ENDITEM,
		"Name=HazardGrade", "Value=", ENDITEM,
		"Name=NatureofBusiness", "Value=", ENDITEM,
		"Name=MarketSegment", "Value={cMarketSegment}", ENDITEM,
		"Name=ApplicantSICCode", "Value={cSICCode}", ENDITEM,
		"Name=ApplicantNAICSCode", "Value={cNAICSCode}", ENDITEM,
		"Name=ControllingState", "Value={cControllingState1}", ENDITEM,
		"Name=ProgramAssociation", "Value=FIP", ENDITEM,
		"Name=InsuredOrPrincipal[InsuredOrPrincipalInfo.InsuredOrPrincipalRoleCd='Insured'].InsuredOrPrincipalInfo.PrincipalInfo.CreditScoreInfo.CreditScore", "Value=", ENDITEM,
		//"Name=Applicant3OrMoreFullTimeEmployee", "Value=YES", ENDITEM,
		"Name=OperationOfHazardousMaterial", "Value=NO", ENDITEM,
		//"Name=WorkBlastingDemolitionSandblastingWrecking", "Value=NO", ENDITEM,
		//"Name=WorkHighVoltage480Volts", "Value=NO", ENDITEM,
		//"Name=WorkPetrochemicalNuclearOilPowerPlant", "Value=NO", ENDITEM,
		//"Name=WorkBargesVesselsDocksBridge", "Value=NO", ENDITEM,
		//"Name=ShoringTrenchBoxes5ftDeep", "Value=NO", ENDITEM,
		//"Name=IndustrialBoilerInspectionInstallationRepair", "Value=NO", ENDITEM,
		"Name=LossPast3Years", "Value=NLOSS", ENDITEM,
		"Name=Underwriter", "Value={cUnderWriterId}", ENDITEM,
		"Name=SubAddLine", "Value=NO", ENDITEM,
         LAST);


web_custom_request("IntrapageDTRServlet_23", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"InsuredOrPrincipal@id\" interestLevel=\"2\" pos=\"0\">GUID()</fieldElement><fieldElement uniqueId=\"AddlNamedInsuredRoleCd\" interestLevel=\"2\" pos=\"1\">AI</fieldElement><fieldElement uniqueId=\"AddlNamedInsuredName\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"AddlNamedInsuredDBA\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"AddlNamedInsuredLegalEntity\" interestLevel=\"2\" pos=\"4\"/>"
		"<fieldElement uniqueId=\"AddlNamedInsuredTaxIdType\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">SSN</fieldElement><fieldElement uniqueId=\"InsuredOrPrincipal.GeneralPartyInfo.NameInfo.TitleRelationshipDesc\" interestLevel=\"2\" pos=\"8\"/><page compoundKey=\"workersComp/extendedNamedInsured\" isRoster=\"true\"/><index>InsuredOrPrincipal[1]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
		
	web_custom_request("FrontServlet_17",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t43.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=extendedNamedInsured&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN7}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&InsuredOrPrincipal%40id=GUID()&AddlNamedInsuredRoleCd=AI&AddlNamedInsuredName=&AddlNamedInsuredDBA=&AddlNamedInsuredLegalEntity=&AddlNamedInsuredTaxIdType=FEIN&InsuredOrPrincipal.GeneralPartyInfo.NameInfo.TitleRelationshipDesc=&INDEX.InsuredOrPrincipal=InsuredOrPrincipal%5B1%5D",
		LAST);

	
	web_submit_data("FileUploadServlet_3", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);


	web_url("data_2",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN7}&rnd=15137680193579&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t46.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("01_WC_04_GeneralInformation",LR_AUTO);


	lr_start_transaction("01_WC_05_ExtendedInsureds");

	

/*Correlation comment - Do not change!  Original value='7f8c8638a4d31bdc0579e9fce6b7e726de23f768b7b409ed129614728eb9a866' Name ='CSRF_TOKEN8' Type ='Manual'*/
web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN8",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

//web_reg_find("Text=18%",
//             //"Scope=Body",
//             LAST);
             
	web_submit_data("FrontServlet_21",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t49.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=extendedNamedInsured", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN7}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=InsuredOrPrincipal@id", "Value=GUID()", ENDITEM,
		"Name=AddlNamedInsuredRoleCd", "Value=AI", ENDITEM,
		"Name=AddlNamedInsuredName", "Value=", ENDITEM,
		"Name=AddlNamedInsuredDBA", "Value=", ENDITEM,
		"Name=AddlNamedInsuredLegalEntity", "Value=", ENDITEM,
		"Name=AddlNamedInsuredTaxIdType", "Value=FEIN", ENDITEM,
		"Name=AddlNamedInsuredTaxIdFEIN", "Value=", ENDITEM,
		"Name=InsuredOrPrincipal.GeneralPartyInfo.NameInfo.TitleRelationshipDesc", "Value=", ENDITEM,
		"Name=INDEX.InsuredOrPrincipal", "Value=InsuredOrPrincipal[1]", ENDITEM,
		LAST);

	web_url("data_3",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN8}&rnd=1513768057879&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t50.inf",
		"Mode=HTML",
		LAST);

	
	web_custom_request("FrontServlet_22",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t51.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=Locations&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN8}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&LocationId=GUID()&LocationSystemId=&hiddenAccountClearanceStatus=&MultiResultJSON=&LocationNumber=&LocationDescription=&LocationAddressAddr1=&LocationAddressAddr2=&LocationAddressCity=&LocationAddressState=&LocationAddressZip=&LocationNumEmployees=&LocationHighestFloor=&LocationGEOResult=&LocationGEOPlaceCd=&LocationGEOCensusTract=&LocationGEOCensusBlock=&LocationGEOCountyFIPS=&LocationGEOLatitude=&LocationGEOLongitude=&LocationGEOCountyName=&LocationGEOSubdivisionCode=&LocationAddressAddressValidationFlag=&INDEX.Location=Location%5B1%5D&INDEX.Location=Location%5B1%5D",
     LAST);

	web_submit_data("FileUploadServlet_4", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_WC_05_ExtendedInsureds",LR_AUTO);

	

	lr_start_transaction("01_WC_06_LocationInformation");


   for(i=1;i<19;i++)
	  { 
       	lr_save_int(i,"param");
    	result=atoi(lr_eval_string("{param}"));
    	result=result+1;
    	lr_save_int(result,"result1");
    	

    	
    	
	web_reg_save_param_regexp(
		"ParamName=cLocationZip",
		"RegExp=LocationAddressZip&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);

     	web_reg_save_param_regexp(
		"ParamName=cLocationLatitude",
		"RegExp=LocationGEOLatitude&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     
     web_reg_save_param_regexp(
		"ParamName=cLocationCity",
		"RegExp=LocationAddressCity&quot;:&quot;(.*?)&quot",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     

     
     
     web_reg_save_param_regexp(
		"ParamName=cLocationAddress",
		"RegExp=LocationAddressAddr1&quot;:&quot;(.*?)&quot",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     web_reg_save_param_regexp(
		"ParamName=cLocationState",
		"RegExp=LocationAddressState&quot;:&quot;(.*?)&quot",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     web_reg_save_param_regexp(
		"ParamName=cLocationPlaceCd",
		"RegExp=LocationGEOPlaceCd&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
		"ParamName=cLocationCountry",
		"RegExp=LocationGEOCountyName&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     
     web_reg_save_param_regexp(
		"ParamName=cLocationCensusBlock",
		"RegExp=LocationGEOCensusBlock&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);	
     
     web_reg_save_param_regexp(
		"ParamName=cLocationLongitude",
		"RegExp=LocationGEOLongitude&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
		"ParamName=cLocationCountryFIPS",
		"RegExp=LocationGEOCountyFIPS&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
     web_reg_save_param_regexp(
		"ParamName=cLocationCensusTract",
		"RegExp=LocationGEOCensusTract&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
     
      web_reg_save_param_regexp(
		"ParamName=cLocationSubDivCode",
		"RegExp=LocationGEOSubdivisionCode&quot;:&quot;(.*?)&quot;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"RequestUrl=*/IntrapageDTRServlet*",
		LAST);
    	web_custom_request("IntrapageDTRServlet_25", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"AddressStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"LocationId\" interestLevel=\"2\" pos=\"1\">GUID()</fieldElement><fieldElement uniqueId=\"LocationSystemId\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"hiddenAccountClearanceStatus\" interestLevel=\"2\" pos=\"3\"/><fieldElement uniqueId=\"MultiResultJSON\" interestLevel=\"2\" pos=\"4\"/><fieldElement uniqueId=\""
		"LocationNumber\" interestLevel=\"2\" pos=\"5\">2</fieldElement><fieldElement uniqueId=\"LocationDescription\" interestLevel=\"2\" pos=\"6\"/><fieldElement uniqueId=\"NoSpecificLocation\" interestLevel=\"2\" pos=\"7\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"LocationAddressAddr1\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">{Address1}</fieldElement><fieldElement uniqueId=\"LocationAddressAddr2\" interestLevel=\"4\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\""
		"LocationAddressCity\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">{City}</fieldElement><fieldElement uniqueId=\"LocationAddressState\" interestLevel=\"4\" pos=\"11\" isHot=\"true\">{State}</fieldElement><fieldElement uniqueId=\"LocationAddressZip\" interestLevel=\"4\" pos=\"12\" isOrigin=\"true\" isHot=\"true\">{Zip}</fieldElement><fieldElement uniqueId=\"LocationAddressKeepAddressasEntered\" interestLevel=\"2\" pos=\"13\" isHot=\"true\">0</fieldElement><fieldElement uniqueId=\"LocationNumEmployees\" "
		"interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"LocationHighestFloor\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"LocationGEOResult\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"LocationGEOPlaceCd\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"LocationGEOCensusTract\" interestLevel=\"2\" pos=\"19\"/><fieldElement uniqueId=\"LocationGEOCensusBlock\" interestLevel=\"2\" pos=\"20\"/><fieldElement uniqueId=\"LocationGEOCountyFIPS\" interestLevel=\"2\" "
		"pos=\"21\"/><fieldElement uniqueId=\"LocationGEOLatitude\" interestLevel=\"2\" pos=\"22\"/><fieldElement uniqueId=\"LocationGEOLongitude\" interestLevel=\"2\" pos=\"23\"/><fieldElement uniqueId=\"LocationGEOCountyName\" interestLevel=\"2\" pos=\"24\"/><fieldElement uniqueId=\"LocationGEOSubdivisionCode\" interestLevel=\"2\" pos=\"25\"/><fieldElement uniqueId=\"LocationAddressAddressValidationFlag\" interestLevel=\"2\" pos=\"26\" isHot=\"true\"/><page compoundKey=\"workersComp/Locations\" isRoster="
		"\"true\"/><index>Location[1]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
//	
//  web_custom_request("FrontServlet_18",
//		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=1",
//		"Method=POST",
//		"Resource=0",
//		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
//		"Snapshot=t45.inf",
//		"Mode=HTML",
//		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
//		"Body=HASH={HASH}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=Locations&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN8}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&LocationId=GUID()&LocationSystemId=&hiddenAccountClearanceStatus=&MultiResultJSON=&LocationNumber={result}LocationDescription=&LocationAddressAddr1={Address1}&LocationAddressAddr2=&LocationAddressCity={City}&LocationAddressState={State}&LocationAddressZip={Zip}&LocationNumEmployees=&LocationHighestFloor=&LocationGEOResult=&LocationGEOPlaceCd=&LocationGEOCensusTract=&LocationGEOCensusBlock=&LocationGEOCountyFIPS=&LocationGEOLatitude=&LocationGEOLongitude=&LocationGEOCountyName=&LocationGEOSubdivisionCode=&LocationAddressAddressValidationFlag=&INDEX.Location=Location%5B1%5D&INDEX.Location=Location%5B{param}%5D",
//		LAST);

/*Correlation comment - Do not change!  Original value='1579924357' Name ='HASH2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH2",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
    web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_9",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
    	
    	web_submit_data("FrontServlet_30",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t59.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN8}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Add", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=LocationId", "Value=GUID()", ENDITEM,
		"Name=LocationSystemId", "Value=", ENDITEM,
		"Name=hiddenAccountClearanceStatus", "Value=", ENDITEM,
		"Name=MultiResultJSON", "Value=", ENDITEM,
		"Name=LocationNumber", "Value={result1}", ENDITEM,
		"Name=LocationDescription", "Value=", ENDITEM,
		"Name=LocationAddressAddr1", "Value={cLocationAddress}", ENDITEM,
		"Name=LocationAddressAddr2", "Value=", ENDITEM,
		"Name=LocationAddressCity", "Value={cLocationCity}", ENDITEM,
		"Name=LocationAddressState", "Value={cLocationState}", ENDITEM,
		"Name=LocationAddressZip", "Value={cLocationZip}", ENDITEM,
		"Name=LocationNumEmployees", "Value=", ENDITEM,
		"Name=LocationHighestFloor", "Value=", ENDITEM,
		"Name=LocationGEOResult", "Value=GS01", ENDITEM,
		"Name=LocationGEOPlaceCd", "Value={cLocationPlaceCd}", ENDITEM,
		"Name=LocationGEOCensusTract", "Value={cLocationCensusTract}", ENDITEM,
		"Name=LocationGEOCensusBlock", "Value={cLocationCensusBlock}", ENDITEM,
		"Name=LocationGEOCountyFIPS", "Value={cLocationCountryFIPS}", ENDITEM,
		"Name=LocationGEOLatitude", "Value={cLocationLatitude}", ENDITEM,
		"Name=LocationGEOLongitude", "Value={cLocationLongitude}", ENDITEM,
		"Name=LocationGEOCountyName", "Value={cLocationCountry}", ENDITEM,
		"Name=LocationGEOSubdivisionCode", "Value={cLocationSubDivCode}", ENDITEM,
		"Name=LocationAddressAddressValidationFlag", "Value=EXACTMATCH", ENDITEM,
		"Name=INDEX.Location", "Value=Location[{param}]", ENDITEM,
		"Name=INDEX.Location", "Value=Location[{param}]", ENDITEM,
		LAST);

    	
    	web_custom_request("FrontServlet_32",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t61.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=Locations&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_9}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&LocationId=GUID()&LocationSystemId=&hiddenAccountClearanceStatus=&MultiResultJSON=&LocationNumber=&LocationDescription=&LocationAddressAddr1=&LocationAddressAddr2=&LocationAddressCity=&LocationAddressState=&LocationAddressZip=&LocationNumEmployees=&LocationHighestFloor=&LocationGEOResult=&LocationGEOPlaceCd=&LocationGEOCensusTract=&LocationGEOCensusBlock=&LocationGEOCountyFIPS=&LocationGEOLatitude=&LocationGEOLongitude=&LocationGEOCountyName=&LocationGEOSubdivisionCode=&LocationAddressAddressValidationFlag=&INDEX.Location=Location%5B{result1}%5D&INDEX.Location=Location%5B{result1}%5D",
		LAST);



		web_url("data_6",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN_9}&rnd=1515477357931&transaction_id=workersComp",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t66.inf",
		"Mode=HTML",
		LAST);

   web_submit_data("FileUploadServlet_6", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t63.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);
       
       }
       
   web_reg_save_param_ex(
		"ParamName=HASH_3",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);
   
       /*Correlation comment - Do not change!  Original value='dc70a6b5daf470907d9610035142ffb712c871e3541bbfdb19ec8d1cdb677c69' Name ='CSRF_TOKEN_2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN13",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
       web_submit_data("FrontServlet_34",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t65.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH2}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=Locations", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_9}", ENDITEM,
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
		"Name=LocationNumEmployees", "Value=", ENDITEM,
		"Name=LocationHighestFloor", "Value=", ENDITEM,
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
		"Name=INDEX.Location", "Value=Location[{result1}]", ENDITEM,
		"Name=INDEX.Location", "Value=Location[{result1}]", ENDITEM,
		LAST);
	
   	web_url("data_6",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN13}&rnd=1515477357931&transaction_id=workersComp",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t66.inf",
		"Mode=HTML",
		LAST);

	

	web_submit_data("FrontServlet_36",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t68.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH2}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=coverage", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN13}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=AgencyCarrierName", "Value=SECURA MUTUAL", ENDITEM,
		"Name=additionalCompanyInfo", "Value=", ENDITEM,
		"Name=employersLiabilityLimit", "Value=", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_7", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

   
	lr_end_transaction("01_WC_06_LocationInformation",LR_AUTO);

	

	lr_start_transaction("01_WC_07_PolicyInformation");




/*Correlation comment - Do not change!  Original value='4ed369756bc520c31d39087140d14fd202aa27ebaf92e38cc7defa1dd259bad4' Name ='CSRF_TOKEN14' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_14",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
		web_reg_save_param_regexp(
		"ParamName=index_1",
		"RegExp=Minnesota.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
		web_reg_save_param_regexp(
		"ParamName=index_2",
		"RegExp=Missouri.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=index_3",
		"RegExp=Wisconsin.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

web_reg_save_param_regexp(
		"ParamName=index_4",
		"RegExp=Kansas.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

web_reg_save_param_regexp(
		"ParamName=index_5",
		"RegExp=Iowa.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
web_reg_save_param_regexp(
		"ParamName=index_6",
		"RegExp=Indiana.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
web_reg_save_param_regexp(
		"ParamName=index_7",
		"RegExp=Illinois.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
web_reg_save_param_regexp(
		"ParamName=index_8",
		"RegExp=Michigan.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
web_reg_save_param_regexp(
		"ParamName=index_9",
		"RegExp=Pennsylvania.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
web_reg_save_param_regexp(
		"ParamName=index_10",
		"RegExp=Kentucky.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

    web_reg_save_param_regexp(
      	"ParamName=index_11",
		"RegExp=Colorado.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
		web_reg_save_param_regexp(
		"ParamName=index_12",
		"RegExp=Arizona.+\\r\\n.+\\r\\n.+\\r\\n.+WorkCompRateState\\[(.*?)\\]&EDIT",
		"Group=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
             
	web_submit_data("FrontServlet_50",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t88.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_3}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=coverage", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN13}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=AgencyCarrierName", "Value=SECURA MUTUAL", ENDITEM,
		"Name=additionalCompanyInfo", "Value=", ENDITEM,
		"Name=employersLiabilityLimit", "Value=1000000/1000000/1000000", ENDITEM,
		"Name=policyVoluntary", "Value=VOL", ENDITEM,	
		LAST);




	web_url("data_8",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN_14}&rnd=1513768302838&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t90.inf",
		"Mode=HTML",
		LAST);

	

	web_custom_request("FrontServlet_52",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t91.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH_3}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=true&CSRF_TOKEN={CSRF_TOKEN_14}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B2%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B2%5D",
		LAST);

	web_submit_data("FileUploadServlet_9", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t92.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	
	lr_end_transaction("01_WC_07_PolicyInformation",LR_AUTO);
	
	

	lr_start_transaction("01_08_StateRating_01_Minnesota");



/*Correlation comment - Do not change!  Original value='7bb42bde817f3eba30b86aa4cd853af65ab91708fdf8be0b2480506cfe4028be' Name ='CSRF_TOKEN_state' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_mis",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid1",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd1",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	
		
	web_url("FrontServlet_13",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_1}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_14}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t5.inf",
		"Mode=HTML",
		LAST);


	web_submit_data("FrontServlet_14",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"EncodeAtSign=YES",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_1}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_14}",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_mis}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=RateFactorMessage", "Value=", ENDITEM,
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid1}", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd1}", ENDITEM,
		"Name=StateRatingFactorState", "Value=MN", ENDITEM,
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM,
		"Name=RiskID", "Value=", ENDITEM,
		"Name=StateRatingFactorSRA", "Value=", ENDITEM,
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM,
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM,
		"Name=StatusofRateFilingCode", "Value=", ENDITEM,
		"Name=ContingentIndicator", "Value=", ENDITEM,
		"Name=RatingEffDate", "Value=", ENDITEM,
		"Name=RatingEffYear", "Value=", ENDITEM,
		"Name=drugFreeCreditProgramAL", "Value=0", ENDITEM,
		"Name=managedCareAL", "Value=0", ENDITEM,
		"Name=safetyCreditAL", "Value=0", ENDITEM,
		"Name=StateRatingFactorCBDR", "Value=0", ENDITEM,
		"Name=StateRatingFactorRTWRK", "Value=0", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_1}]", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_1}]", ENDITEM,
		LAST);

	

	web_custom_request("IntrapageDTRServlet_3",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/plain",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_1}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_14}",
		"Mode=HTML",
		"EncType=text/xml",
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">N356</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd1}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">MN</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos"
		"=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><fieldElement uniqueId=\"managedCareAL\" interestLevel=\"4\" pos=\"1\">0</fieldElement><fieldElement uniqueId=\"safetyCreditAL\" interestLevel=\"4\" pos=\"2\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorCBDR\" interestLevel=\"2\" pos=\"15\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorRTWRK\" interestLevel=\"2\" pos=\"16\""
		">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_1}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>",
		LAST);

	web_submit_data("FileUploadServlet_4",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet",
		"Method=POST",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_1}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_14}",
		"Mode=HTML",
		ITEMDATA,
		"Name=requestType", "Value=list", ENDITEM,
		LAST);



	web_custom_request("IntrapageDTRServlet_4",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/plain",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_1}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_14}",
		"Mode=HTML",
		"EncType=text/xml",
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid1}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd1}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MN</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">500</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">913344731</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId="
		"\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><fieldElement uniqueId=\"managedCareAL\" interestLevel=\"4\" pos=\"1\">0</fieldElement><fieldElement uniqueId=\"safetyCreditAL\" interestLevel=\"4\" pos=\"2\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorCBDR\" interestLevel=\"2\" pos=\"15\">0</fieldElement><fieldElement uniqueId=\"State"
		"RatingFactorRTWRK\" interestLevel=\"2\" pos=\"16\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_1}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>",
		LAST);



	web_custom_request("IntrapageDTRServlet_5",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/plain",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_1}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_14}",
		"Mode=HTML",
		"EncType=text/xml",
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid1}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd1}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MN</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">500</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">913344731</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" isOrigin=\"true\" isHot=\"true\">0.9</fieldElement><field"
		"Element uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><fieldElement uniqueId=\"managedCareAL\" interestLevel=\"4\" pos=\"1\">0</fieldElement><fieldElement uniqueId=\"safetyCreditAL\" interestLevel=\"4\" pos=\"2\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorCBDR\" interestLevel=\"2\" pos=\"15\">0</fieldElement><fieldElement"
		" uniqueId=\"StateRatingFactorRTWRK\" interestLevel=\"2\" pos=\"16\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_1}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>",
		LAST);


/*Correlation comment - Do not change!  Original value='2044421492' Name ='HASH_state2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state2",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state2",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_18",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_1}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_14}",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_mis}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=Save", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=RateFactorMessage", "Value=", ENDITEM,
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid1}", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd1}", ENDITEM,
		"Name=StateRatingFactorState", "Value=MN", ENDITEM,
		"Name=WorkCompDeductibleAmount", "Value=500", ENDITEM,
		"Name=RiskID", "Value=913344731", ENDITEM,
		"Name=StateRatingFactorAREM", "Value=0.9", ENDITEM,
		"Name=StateRatingFactorSRA", "Value=", ENDITEM,
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM,
		"Name=StateRatingFactorWVSUB", "Value=WVSUB", ENDITEM,
		"Name=StatusofRateFilingCode", "Value=", ENDITEM,
		"Name=ContingentIndicator", "Value=", ENDITEM,
		"Name=RatingEffDate", "Value=", ENDITEM,
		"Name=RatingEffYear", "Value=", ENDITEM,
		"Name=drugFreeCreditProgramAL", "Value=1", ENDITEM,
		"Name=managedCareAL", "Value=1", ENDITEM,
		"Name=safetyCreditAL", "Value=1", ENDITEM,
		"Name=StateRatingFactorCBDR", "Value=1", ENDITEM,
		"Name=StateRatingFactorRTWRK", "Value=0", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_1}]", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_1}]", ENDITEM,
		LAST);

	web_custom_request("FrontServlet_19", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state2}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state2}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
		LAST);

	
	web_custom_request("IntrapageDTRServlet_6", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
		

	web_submit_data("FileUploadServlet_5", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_01_Minnesota",LR_AUTO);

	lr_start_transaction("01_08_StateRating_02_Pens");


		web_reg_save_param_ex(
		"ParamName=compstateid2",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd2",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);
	
	
/*Correlation comment - Do not change!  Original value='{HASH_state3}' Name ='HASH_state3' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state3",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state4}' Name ='CSRF_TOKEN_state4' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=CSRF_TOKEN_state4",
		"LB=id=\"CSRF_TOKEN\" value=\"",
		"RB=\"",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_url("FrontServlet_24",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_9}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state2}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t7.inf",
		"Mode=HTML",
		EXTRARES,
		LAST);


	web_submit_data("FrontServlet_25", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_9}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state2}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state3}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state4}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid2}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd2}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=PA", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=safetyCreditAL", "Value=0", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_9}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_9}]", ENDITEM, 
				LAST);

	web_submit_data("FileUploadServlet_6",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet",
		"Method=POST",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_9}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state2}",
		"Mode=HTML",
		ITEMDATA,
		"Name=requestType", "Value=list", ENDITEM,
		LAST);

	web_custom_request("IntrapageDTRServlet_7", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_9}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state2}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid2}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd2}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">PA</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/>"
		"<fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"safetyCreditAL\" interestLevel=\"4\" pos=\"2\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_9}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	//r_thinkk_time(12);

	web_custom_request("IntrapageDTRServlet_8", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_9}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state2}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid2}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd2}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">PA</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">2500</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">9132301</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel="
		"\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" "
		"interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"safetyCreditAL\" interestLevel=\"4\" pos=\"2\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_9}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
;

	web_custom_request("IntrapageDTRServlet_9", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_9}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state2}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid2}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd2}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">PA</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">2500</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">9132301</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" "
		"isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"4\" pos=\"10\" isOrigin=\"true\" isHot=\"true\">0.89</fieldElement><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\""
		"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"safetyCreditAL\" interestLevel=\"4\" pos=\"2\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_9}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

/*Correlation comment - Do not change!  Original value='2044421492' Name ='HASH_state2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state6",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state6",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_26",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_9}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state2}",
		"Snapshot=t8.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_state3}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state4}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=Save", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=RateFactorMessage", "Value=", ENDITEM,
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid2}", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd2}", ENDITEM,
		"Name=StateRatingFactorState", "Value=PA", ENDITEM,
		"Name=WorkCompDeductibleAmount", "Value=2500", ENDITEM,
		"Name=RiskID", "Value=9132301", ENDITEM,
		"Name=StateRatingFactorAREM", "Value=", ENDITEM,
		"Name=StateRatingFactorMERIT", "Value=0.89", ENDITEM,
		"Name=StateRatingFactorSRA", "Value=", ENDITEM,
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM,
		"Name=StateRatingFactorWVSUB", "Value=Secura_NWVSUB", ENDITEM,
		"Name=StatusofRateFilingCode", "Value=", ENDITEM,
		"Name=ContingentIndicator", "Value=", ENDITEM,
		"Name=RatingEffDate", "Value=", ENDITEM,
		"Name=RatingEffYear", "Value=", ENDITEM,
		"Name=safetyCreditAL", "Value=0", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_9}]", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_9}]", ENDITEM,
		LAST);

	

	web_custom_request("FrontServlet_27", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state6}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state6}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
		LAST);



	web_custom_request("IntrapageDTRServlet_10", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_7", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	
	lr_end_transaction("01_08_StateRating_02_Pens",LR_AUTO);

	lr_start_transaction("01_08_StateRating_03_Wisconsin");

	
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state5",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state5",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid3",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd3",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	

	web_url("FrontServlet_30", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_3}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state6}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t9.inf", 
		"Mode=HTML",  
		LAST);



	web_submit_data("FrontServlet_31", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_3}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state6}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state5}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state5}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid3}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd3}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=WI", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=DividendPlanSafetyGroup", "Value=", ENDITEM, 
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_3}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_3}]", ENDITEM, 
		LAST);



	web_custom_request("IntrapageDTRServlet_11", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_3}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state6}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid3}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd3}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">WI</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\""
		"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"DividendPlanSafetyGroup\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/>"
		"<fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_3}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_8", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_3}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state6}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);


	web_custom_request("IntrapageDTRServlet_12", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_3}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state6}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid3}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd3}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">WI</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">970058543</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2"
		"\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"DividendPlanSafetyGroup\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\""
		"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_3}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);


	web_custom_request("IntrapageDTRServlet_13", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_3}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state6}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid3}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd3}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">WI</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">970058543</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" isOrigin=\"true\" isHot=\"true\">0.08</fieldElement><fieldElement uniqueId=\"StateRatingFactorMERIT\" "
		"interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"DividendPlanSafetyGroup\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" "
		"interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_3}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);


	/*Correlation comment - Do not change!  Original value='2044421492' Name ='HASH_state2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state7",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state7",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
	
	web_submit_data("FrontServlet_34", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_3}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state6}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state5}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state5}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid3}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd3}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=WI", ENDITEM, 
		"Name=RiskID", "Value=970058543", ENDITEM, 
		"Name=StateRatingFactorAREM", "Value=0.08", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=DividendPlanSafetyGroup", "Value=", ENDITEM, 
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=Secura_FWVSB", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_3}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_3}]", ENDITEM, 
	    LAST);



	web_custom_request("FrontServlet_35", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state7}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state7}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D",
		LAST);

	web_custom_request("IntrapageDTRServlet_14", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_9", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_03_Wisconsin",LR_AUTO);

	lr_start_transaction("01_08_StateRating_04_Missouri");

	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state8",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state8",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid4",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd4",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	


	web_url("FrontServlet_36", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_2}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state7}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);


	web_submit_data("FrontServlet_37", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_2}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state7}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state8}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state8}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid4}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd4}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=MO", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_2}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_2}]", ENDITEM, 
		LAST);

	web_submit_data("FileUploadServlet_10", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_2}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state7}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_custom_request("IntrapageDTRServlet_15", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_2}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state7}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid4}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd4}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">MO</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/>"
		"<fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_2}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_16", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_2}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state7}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid4}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd4}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MO</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4"
		"\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement "
		"uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_2}]</index><target>WorkCompPolicyQuoteInqRq</target></"
		"intraPageDTRRequest>", 
		LAST);



	web_custom_request("IntrapageDTRServlet_17", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_2}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state7}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid4}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd4}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MO</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">1000</fieldElement><fieldElement uniqueId=\"RiskID\" "
		"interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">240976099</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" "
		"interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_2}]</index><target"
		">WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_18", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_2}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state7}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid4}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd4}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MO</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">1000</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">240976099</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" "
		"isOrigin=\"true\" isHot=\"true\">0.85</fieldElement><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\">F</fieldElement><fieldElement"
		" uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\">N</fieldElement><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\">2017-09-17</fieldElement><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\">2017</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_2}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);



	/*Correlation comment - Do not change!  Original value='2044421492' Name ='HASH_state2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state9",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state9",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_41", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_2}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state7}", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state8}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state8}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid4}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd4}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=MO", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=1000", ENDITEM, 
		"Name=RiskID", "Value=240976099", ENDITEM, 
		"Name=StateRatingFactorAREM", "Value=0.85", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=Secura_SWVSB", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=F", ENDITEM, 
		"Name=ContingentIndicator", "Value=N", ENDITEM, 
		"Name=RatingEffDate", "Value=2017-09-17", ENDITEM, 
		"Name=RatingEffYear", "Value=2017", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_2}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_2}]", ENDITEM, 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("FrontServlet_42", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state9}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state9}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
		LAST);



	web_custom_request("IntrapageDTRServlet_19", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_11", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_04_Missouri",LR_AUTO);

	lr_start_transaction("01_08_StateRating_05_Illionis");
    
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state10",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state10",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid5",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd5",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);
	

	web_url("FrontServlet_45", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_7}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state9}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	

	web_submit_data("FrontServlet_46", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_7}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state9}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state10}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state10}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid5}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd5}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=IL", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_7}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_7}]", ENDITEM, 
		LAST);

	web_submit_data("FileUploadServlet_12", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_7}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state9}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	
	web_custom_request("IntrapageDTRServlet_20", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_7}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state9}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid5}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd5}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">IL</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/>"
		"<fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_7}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_21", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_7}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state9}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid5}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd5}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IL</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4"
		"\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement "
		"uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_7}]</index><target>WorkCompPolicyQuoteInqRq</target></"
		"intraPageDTRRequest>", 
		LAST);

	

	web_custom_request("IntrapageDTRServlet_22", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_7}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state9}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid5}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd5}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IL</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">1000</fieldElement><fieldElement uniqueId=\"RiskID\" "
		"interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">127119635</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" "
		"interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_7}]</index><target"
		">WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_23", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_7}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state9}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid5}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd5}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IL</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">1000</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">127119635</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" "
		"isOrigin=\"true\" isHot=\"true\">1.07</fieldElement><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorCPAP\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\">F</fieldElement><fieldElement"
		" uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\">N</fieldElement><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\">2017-09-01</fieldElement><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\">2017</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_7}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

     web_reg_save_param_ex(
		"ParamName=HASH_state11",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state11",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_51", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_7}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state9}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state10}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state10}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid5}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd5}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=IL", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=1000", ENDITEM, 
		"Name=RiskID", "Value=127119635", ENDITEM, 
		"Name=StateRatingFactorAREM", "Value=1.07", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorCPAP", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=F", ENDITEM, 
		"Name=ContingentIndicator", "Value=N", ENDITEM, 
		"Name=RatingEffDate", "Value=2017-09-01", ENDITEM, 
		"Name=RatingEffYear", "Value=2017", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_7}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_7}]", ENDITEM, 
		LAST);

	web_custom_request("FrontServlet_52", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state11}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state11}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
		LAST);

	
	web_submit_data("FileUploadServlet_13", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_custom_request("IntrapageDTRServlet_24", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	lr_end_transaction("01_08_StateRating_05_Illionis",LR_AUTO);

	lr_start_transaction("01_08_StateRating_06_Indiana");



/*Correlation comment - Do not change!  Original value='122f1a1973b5c6b0071ddaf372016a17c6b72652929f88eefebaac797c3d208c' Name ='CSRF_TOKEN_state11' Type ='Manual'*/

web_reg_save_param_ex(
		"ParamName=HASH_state12",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state12",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

//Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid7",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd7",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	

	web_url("FrontServlet_57", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_6}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state11}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);



	web_submit_data("FrontServlet_58",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"EncodeAtSign=YES",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_6}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state11}",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_state12}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state12}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=RateFactorMessage", "Value=", ENDITEM,
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid7}", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd7}", ENDITEM,
		"Name=StateRatingFactorState", "Value=IN", ENDITEM,
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM,
		"Name=RiskID", "Value=", ENDITEM,
		"Name=StateRatingFactorSRA", "Value=", ENDITEM,
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM,
		"Name=StatusofRateFilingCode", "Value=", ENDITEM,
		"Name=ContingentIndicator", "Value=", ENDITEM,
		"Name=RatingEffDate", "Value=", ENDITEM,
		"Name=RatingEffYear", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_6}]", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_6}]", ENDITEM,
		LAST);


	web_custom_request("IntrapageDTRServlet_25", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_6}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state11}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid7}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd7}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">IN</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/>"
		"<fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_6}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_14", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_6}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state11}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);



	web_custom_request("IntrapageDTRServlet_26", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_6}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state11}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid7}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd7}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IN</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4"
		"\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement "
		"uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_6}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);


	web_custom_request("IntrapageDTRServlet_27", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_6}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state11}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid7}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd7}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IN</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">2000</fieldElement><fieldElement uniqueId=\"RiskID\" "
		"interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">130107419</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" "
		"interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_6}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_28", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_6}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state11}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid7}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd7}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IN</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">2000</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">130107419</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" "
		"isOrigin=\"true\" isHot=\"true\">0.79</fieldElement><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\">F</fieldElement><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\">N</fieldElement>"
		"<fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\">2017-10-01</fieldElement><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\">2017</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_6}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=HASH_state13",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state13",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_61",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_6}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state11}",
		"Snapshot=t16.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH_state12}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state12}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=Save", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=RateFactorMessage", "Value=", ENDITEM,
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid7}", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd7}", ENDITEM,
		"Name=StateRatingFactorState", "Value=IN", ENDITEM,
		"Name=WorkCompDeductibleAmount", "Value=2000", ENDITEM,
		"Name=RiskID", "Value=130107419", ENDITEM,
		"Name=StateRatingFactorAREM", "Value=0.79", ENDITEM,
		"Name=StateRatingFactorSRA", "Value=", ENDITEM,
		"Name=StateRatingFactorWVSUB", "Value=WVSUB", ENDITEM,
		"Name=StatusofRateFilingCode", "Value=F", ENDITEM,
		"Name=ContingentIndicator", "Value=N", ENDITEM,
		"Name=RatingEffDate", "Value=2017-10-01", ENDITEM,
		"Name=RatingEffYear", "Value=2017", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_6}]", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_6}]", ENDITEM,
		LAST);



	web_custom_request("FrontServlet_62", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state13}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state13}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
		LAST);

	web_custom_request("IntrapageDTRServlet_29", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_15", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_06_Indiana",LR_AUTO);


	lr_start_transaction("01_08_StateRating_07_Iowa");

		web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state14",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state14",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid8",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd8",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	
		



	web_url("FrontServlet_65",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_5}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state13}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t17.inf",
		"Mode=HTML",
		LAST);



	web_submit_data("FrontServlet_66", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_5}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state13}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state14}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state14}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid8}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd8}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=IA", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_5}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_5}]", ENDITEM, 
		LAST);

	

	web_custom_request("IntrapageDTRServlet_30", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_5}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state13}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid8}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd8}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">IA</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/>"
		"<fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_5}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_16", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_5}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state13}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_custom_request("IntrapageDTRServlet_31", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_5}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state13}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid8}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd8}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IA</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4"
		"\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement "
		"uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_5}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	//r_thinkk_time(6);

	web_custom_request("IntrapageDTRServlet_32", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_5}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state13}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid8}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd8}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IA</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">3000</fieldElement><fieldElement uniqueId=\"RiskID\" "
		"interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">140415839</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" "
		"interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_5}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_33", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_5}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state13}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid8}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd8}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">IA</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">3000</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">140415839</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" "
		"isOrigin=\"true\" isHot=\"true\">0.94</fieldElement><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\">F</fieldElement><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\">N</fieldElement>"
		"<fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\">2017-11-28</fieldElement><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\">2017</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_5}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FrontServlet_68", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_5}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state13}", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state14}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state14}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateprovcd8}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd8}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=IA", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=3000", ENDITEM, 
		"Name=RiskID", "Value=140415839", ENDITEM, 
		"Name=StateRatingFactorAREM", "Value=0.94", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=Secura_SWVSB", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=F", ENDITEM, 
		"Name=ContingentIndicator", "Value=N", ENDITEM, 
		"Name=RatingEffDate", "Value=2017-11-28", ENDITEM, 
		"Name=RatingEffYear", "Value=2017", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_5}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_5}]", ENDITEM, 
		LAST);

	web_custom_request("IntrapageDTRServlet_34", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_17", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_07_Iowa",LR_AUTO);

	

	lr_start_transaction("01_08_StateRating_08_Kansas");

	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state15",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state15",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid9",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd9",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_url("FrontServlet_71", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_4}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state14}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t19.inf", 
		"Mode=HTML",
		LAST);
	
	web_submit_data("FileUploadServlet_18", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_4}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state14}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_submit_data("FrontServlet_72", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_4}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state14}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state15}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state15}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid9}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd9}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=KS", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_4}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_4}]", ENDITEM, 
		LAST);

	web_custom_request("IntrapageDTRServlet_35", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_4}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state14}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid9}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd9}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">KS</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/>"
		"<fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_4}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_36", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_4}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state14}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid9}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd9}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">KS</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4"
		"\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement "
		"uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_4}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_37", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_4}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state14}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid9}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd9}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">KS</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">250</fieldElement><fieldElement uniqueId=\"RiskID\" "
		"interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">150546915</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" "
		"interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_4}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_38", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_4}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state14}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid9}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd9}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">KS</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">250</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">150546915</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" "
		"isOrigin=\"true\" isHot=\"true\">0.81</fieldElement><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\">F</fieldElement><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\">N</fieldElement>"
		"<fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\">2017-09-17</fieldElement><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\">2017</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_4}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
		
	/*Correlation comment - Do not change!  Original value='2044421492' Name ='HASH_state2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state20",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state20",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);


	web_submit_data("FrontServlet_75", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_4}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state14}", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state15}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state15}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid9}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd9}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=KS", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=250", ENDITEM, 
		"Name=RiskID", "Value=150546915", ENDITEM, 
		"Name=StateRatingFactorAREM", "Value=0.81", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=WVSUB", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=F", ENDITEM, 
		"Name=ContingentIndicator", "Value=N", ENDITEM, 
		"Name=RatingEffDate", "Value=2017-09-17", ENDITEM, 
		"Name=RatingEffYear", "Value=2017", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_4}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_4}]", ENDITEM, 
		LAST);

	

	web_custom_request("FrontServlet_76", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state20}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state20}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
		LAST);


	web_custom_request("IntrapageDTRServlet_39", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_19", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_08_Kansas",LR_AUTO);

	//r_thinkk_time(14);

	lr_start_transaction("01_08_StateRating_09_Arizona");

	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state16",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state16",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid10",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd10",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	


	web_url("FrontServlet_79", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_12}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state20}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);



	web_submit_data("FrontServlet_80", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_12}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state20}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state16}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state16}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid10}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd10}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=AZ", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=drugFreeCreditProgramAL", "Value=0", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_12}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_12}]", ENDITEM, 
		LAST);

	

	web_custom_request("IntrapageDTRServlet_40", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_12}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state20}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid10}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd10}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">AZ</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\""
		"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\""
		"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_12}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_41", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_12}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state20}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid10}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd10}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">AZ</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" "
		"interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement "
		"uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_12}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	/*Correlation comment - Do not change!  Original value='2044421492' Name ='HASH_state2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state17",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state17",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);


	web_submit_data("FrontServlet_85", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_12}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state20}", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state16}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state16}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid10}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd10}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=AZ", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=Secura_SWVSB", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=drugFreeCreditProgramAL", "Value=1", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_12}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_12}]", ENDITEM,  
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("FrontServlet_86", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state17}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state17}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
		LAST);

	

	web_custom_request("IntrapageDTRServlet_42", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_21", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_09_Arizona",LR_AUTO);

	
	lr_start_transaction("01_08_StateRating_10_Colorado");


web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state18",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state18",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid11",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd11",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_url("FrontServlet_89", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_11}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state17}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);


	web_submit_data("FileUploadServlet_22", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_11}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state17}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_custom_request("IntrapageDTRServlet_43", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_11}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state17}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid11}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd11}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">CO</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/>"
		"<fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"managedCareAL\" interestLevel=\"4\" pos=\"1\">0</fieldElement><fieldElement uniqueId=\"safetyCreditAL\" interestLevel=\"4\" pos=\"2\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_11}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_44", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_11}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state17}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid11}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd11}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">CO</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4"
		"\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement "
		"uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"managedCareAL\" interestLevel=\"4\" pos=\"1\">0</fieldElement><fieldElement uniqueId=\"safetyCreditAL\" interestLevel=\"4\" pos=\"2\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index"
		">WorkCompLineBusiness.WorkCompRateState[{index_11}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FrontServlet_93", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_11}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state17}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state18}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state18}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid11}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd11}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=CO", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=managedCareAL", "Value=0", ENDITEM, 
		"Name=safetyCreditAL", "Value=0", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_11}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_11}]", ENDITEM, 
		LAST);

web_reg_save_param_ex(
		"ParamName=HASH_state19",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state19",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_94", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_11}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state17}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state18}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state18}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid11}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd11}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=CO", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=500", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=Secura_NWVSUB", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=managedCareAL", "Value=1", ENDITEM, 
		"Name=safetyCreditAL", "Value=0", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_11}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_11}]", ENDITEM, 
		LAST);


	web_custom_request("IntrapageDTRServlet_45", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_23", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_10_Colorado",LR_AUTO);



	lr_start_transaction("01_08_StateRating_11_Michigan");

 web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state20",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state20",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid12",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd12",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
	web_url("FrontServlet_97", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t25.inf", 
		LAST);

	
	web_submit_data("FrontServlet_98", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state20}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state20}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid12}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd12}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=MI", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=StateRatingFactorWC01", "Value=0", ENDITEM, 
		"Name=StateRatingFactorWC02", "Value=0", ENDITEM, 
		"Name=StateRatingFactorWC03", "Value=0", ENDITEM, 
		"Name=StateRatingFactorWC04", "Value=0", ENDITEM, 
		"Name=StateRatingFactorWC05", "Value=0", ENDITEM, 
		"Name=StateRatingFactorNOEmpH", "Value=", ENDITEM, 
		"Name=StateRatingFactorToNumberEp", "Value=", ENDITEM, 
		"Name=StateRatingFactorWC06", "Value=0", ENDITEM, 
		"Name=StateRatingFactorEmpR1", "Value=", ENDITEM, 
		"Name=StateRatingFactorEmpR2", "Value=", ENDITEM, 
		"Name=StateRatingFactorEmpR3", "Value=", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_8}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_8}]", ENDITEM, 
		LAST);



	web_submit_data("FileUploadServlet_24", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_custom_request("IntrapageDTRServlet_46", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid12}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd12}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">MI</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/>"
		"<fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"StateRatingFactorWC01\" interestLevel=\"2\" pos=\"3\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC02\" interestLevel=\"2\" pos=\"4\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC03\" interestLevel=\"2\" pos=\"5\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC04\" interestLevel=\"2\" pos=\"6\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC05\" "
		"interestLevel=\"2\" pos=\"7\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorNOEmpH\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"StateRatingFactorToNumberEp\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"StateRatingFactorWC06\" interestLevel=\"2\" pos=\"10\">0</fieldElement><fieldElement uniqueId=\"StateRatingMILabel\" interestLevel=\"2\" pos=\"11\">Please enter the prior 3 years of experience modifications.</fieldElement><fieldElement uniqueId=\""
		"StateRatingFactorEmpR1\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorEmpR2\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorEmpR3\" interestLevel=\"2\" pos=\"14\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_8}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);
	
	web_custom_request("IntrapageDTRServlet_47", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience/Merit Mod service unavailable.</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience/Merit Mod service unavailable.</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" "
		"interestLevel=\"2\" pos=\"3\">{compstateid12}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd12}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MI</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM"
		"\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement "
		"uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"StateRatingFactorWC01\" interestLevel=\"2\" pos=\"3\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC02\" interestLevel=\"2\" pos=\"4\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC03\" interestLevel=\"2\" pos=\"5\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC04\" interestLevel=\"2\" pos=\"6\">0</"
		"fieldElement><fieldElement uniqueId=\"StateRatingFactorWC05\" interestLevel=\"2\" pos=\"7\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorNOEmpH\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"StateRatingFactorToNumberEp\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"StateRatingFactorWC06\" interestLevel=\"2\" pos=\"10\">0</fieldElement><fieldElement uniqueId=\"StateRatingMILabel\" interestLevel=\"2\" pos=\"11\">Please enter the prior 3 years of experience "
		"modifications.</fieldElement><fieldElement uniqueId=\"StateRatingFactorEmpR1\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorEmpR2\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorEmpR3\" interestLevel=\"2\" pos=\"14\"/><analyticsFieldData uniqueId=\"StateRatingFactorAREM\"><attribute name=\"isPendingIPDTR\">true</attribute><attribute name=\"analyticsFieldValue\"/></analyticsFieldData><page compoundKey=\"workersComp/ratingFactors\" isRoster=\""
		"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_8}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_48", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience/Merit Mod service unavailable.</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience/Merit Mod service unavailable.</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" "
		"interestLevel=\"2\" pos=\"3\">{compstateid12}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd12}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MI</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM"
		"\" interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement "
		"uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"StateRatingFactorWC01\" interestLevel=\"2\" pos=\"3\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC02\" interestLevel=\"2\" pos=\"4\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC03\" interestLevel=\"2\" pos=\"5\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC04\" interestLevel=\"2\" pos=\"6\">0</"
		"fieldElement><fieldElement uniqueId=\"StateRatingFactorWC05\" interestLevel=\"2\" pos=\"7\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorNOEmpH\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"StateRatingFactorToNumberEp\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"StateRatingFactorWC06\" interestLevel=\"2\" pos=\"10\">0</fieldElement><fieldElement uniqueId=\"StateRatingMILabel\" interestLevel=\"2\" pos=\"11\">Please enter the prior 3 years of experience "
		"modifications.</fieldElement><fieldElement uniqueId=\"StateRatingFactorEmpR1\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorEmpR2\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorEmpR3\" interestLevel=\"2\" pos=\"14\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_8}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	

	web_custom_request("IntrapageDTRServlet_49", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience/Merit Mod service unavailable.</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience/Merit Mod service unavailable.</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" "
		"interestLevel=\"2\" pos=\"3\">{compstateid12}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd12}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MI</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">10000</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">372-133-7-A"
		"</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" "
		"interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"StateRatingFactorWC01\" interestLevel=\"2\" pos=\"3\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC02\" interestLevel=\"2\" pos=\"4\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC03\" interestLevel=\"2\" pos=\"5\">0</fieldElement><fieldElement uniqueId=\""
		"StateRatingFactorWC04\" interestLevel=\"2\" pos=\"6\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC05\" interestLevel=\"2\" pos=\"7\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorNOEmpH\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"StateRatingFactorToNumberEp\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"StateRatingFactorWC06\" interestLevel=\"2\" pos=\"10\">0</fieldElement><fieldElement uniqueId=\"StateRatingMILabel\" interestLevel=\"2\" pos=\""
		"11\">Please enter the prior 3 years of experience modifications.</fieldElement><fieldElement uniqueId=\"StateRatingFactorEmpR1\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorEmpR2\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorEmpR3\" interestLevel=\"2\" pos=\"14\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_8}]</index><target"
		">WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_50", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid12}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd12}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MI</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">10000</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">372-133-7-A</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9"
		"\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"4\" pos=\"10\" isOrigin=\"true\" isHot=\"true\">0.9</fieldElement><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\""
		"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\">2016</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC01\" interestLevel=\"2\" pos=\"3\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC02\" interestLevel=\"2\" pos=\"4\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC03\" interestLevel=\"2\" pos=\"5\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC04\" interestLevel=\"2\" pos=\"6\""
		">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC05\" interestLevel=\"2\" pos=\"7\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorNOEmpH\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"StateRatingFactorToNumberEp\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"StateRatingFactorWC06\" interestLevel=\"2\" pos=\"10\">0</fieldElement><fieldElement uniqueId=\"StateRatingMILabel\" interestLevel=\"2\" pos=\"11\">Please enter the prior 3 years of experience "
		"modifications.</fieldElement><fieldElement uniqueId=\"StateRatingFactorEmpR1\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorEmpR2\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorEmpR3\" interestLevel=\"2\" pos=\"14\"/><analyticsFieldData uniqueId=\"StateRatingFactorAREM\"><attribute name=\"isPendingIPDTR\">true</attribute><attribute name=\"analyticsFieldValue\"/></analyticsFieldData><page compoundKey=\"workersComp/ratingFactors\" isRoster=\""
		"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_8}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);


	web_custom_request("IntrapageDTRServlet_51", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid12}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd12}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">MI</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">10000</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">372-133-7-A</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9"
		"\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"4\" pos=\"10\" isHot=\"true\">0.9</fieldElement><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\""
		"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\">2016</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC01\" interestLevel=\"2\" pos=\"3\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC02\" interestLevel=\"2\" pos=\"4\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC03\" interestLevel=\"2\" pos=\"5\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC04\" interestLevel=\"2\" pos=\"6\""
		">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorWC05\" interestLevel=\"2\" pos=\"7\">0</fieldElement><fieldElement uniqueId=\"StateRatingFactorNOEmpH\" interestLevel=\"2\" pos=\"8\"/><fieldElement uniqueId=\"StateRatingFactorToNumberEp\" interestLevel=\"2\" pos=\"9\"/><fieldElement uniqueId=\"StateRatingFactorWC06\" interestLevel=\"2\" pos=\"10\">0</fieldElement><fieldElement uniqueId=\"StateRatingMILabel\" interestLevel=\"2\" pos=\"11\">Please enter the prior 3 years of experience "
		"modifications.</fieldElement><fieldElement uniqueId=\"StateRatingFactorEmpR1\" interestLevel=\"2\" pos=\"12\"/><fieldElement uniqueId=\"StateRatingFactorEmpR2\" interestLevel=\"2\" pos=\"13\"/><fieldElement uniqueId=\"StateRatingFactorEmpR3\" interestLevel=\"2\" pos=\"14\"/><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_8}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);


web_reg_save_param_ex(
		"ParamName=HASH_state21",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state21",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
	web_submit_data("FrontServlet_105", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_8}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state19}", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state20}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state20}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid12}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd12}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=MI", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=10000", ENDITEM, 
		"Name=RiskID", "Value=372-133-7-A", ENDITEM, 
		"Name=StateRatingFactorAREM", "Value=", ENDITEM, 
		"Name=StateRatingFactorMERIT", "Value=0.9", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=Secura_NWVSUB", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=2016", ENDITEM, 
		"Name=StateRatingFactorWC01", "Value=0", ENDITEM, 
		"Name=StateRatingFactorWC02", "Value=1", ENDITEM, 
		"Name=StateRatingFactorWC03", "Value=1", ENDITEM, 
		"Name=StateRatingFactorWC04", "Value=0", ENDITEM, 
		"Name=StateRatingFactorWC05", "Value=1", ENDITEM, 
		"Name=StateRatingFactorNOEmpH", "Value=25", ENDITEM, 
		"Name=StateRatingFactorToNumberEp", "Value=15", ENDITEM, 
		"Name=StateRatingFactorWC06", "Value=0", ENDITEM, 
		"Name=StateRatingFactorEmpR1", "Value=10", ENDITEM, 
		"Name=StateRatingFactorEmpR2", "Value=20", ENDITEM, 
		"Name=StateRatingFactorEmpR3", "Value=30", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_8}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_8}]", ENDITEM,  
		LAST);

	

	web_custom_request("FrontServlet_106", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state21}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state21}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
		LAST);

	

	web_custom_request("IntrapageDTRServlet_52", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_25", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);


	lr_end_transaction("01_08_StateRating_11_Michigan",LR_AUTO);


	lr_start_transaction("01_08_StateRating_12_Kentucky");
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state22",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-1513205570' Name ='HASH_mis' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state22",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N356' Name ='compstateid1' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=compstateid13",
		"LB=WorkCompLineBusiness_WorkCompRateState_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",  
		LAST);	


	web_reg_save_param_ex(
		"ParamName=compstateprovcd13",
		"LB=WorkCompLineBusiness_WorkCompRateState_StateProvCd_id\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);	

	web_url("FrontServlet_113", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_10}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state21}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	
	web_submit_data("FrontServlet_114", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_10}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state21}", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state22}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state22}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid13}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd13}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=KY", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=", ENDITEM, 
		"Name=RiskID", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=drugFreeCreditProgramAL", "Value=0", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_10}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_10}]", ENDITEM, 
		LAST);


	web_custom_request("IntrapageDTRServlet_53", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_10}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state21}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid13}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd13}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\">KY</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/>"
		"<fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_10}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_26", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_10}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state21}", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_custom_request("IntrapageDTRServlet_54", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_10}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state21}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid13}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd13}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">KY</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"4"
		"\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement "
		"uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_10}]</index><target>WorkCompPolicyQuoteInqRq</target></"
		"intraPageDTRRequest>", 
		LAST);


	web_custom_request("IntrapageDTRServlet_55", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_10}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state21}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\">Experience Mod Service Unavailable. Contact SECRUA agency automation for assistance</fieldElement><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\""
		"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid13}</fieldElement><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd13}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">KY</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">5000</fieldElement><fieldElement uniqueId=\"RiskID\" "
		"interestLevel=\"4\" pos=\"8\" isOrigin=\"true\" isHot=\"true\">160032286</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" "
		"interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><fieldElement uniqueId=\"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_10}]</"
		"index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_custom_request("IntrapageDTRServlet_56", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_10}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state21}", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">{compstateid13}</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">{compstateprovcd13}</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isHot=\"true\">KY</fieldElement><fieldElement uniqueId=\"WorkCompDeductibleAmount\" interestLevel=\"2\" pos=\"7\">5000</fieldElement><fieldElement uniqueId=\"RiskID\" interestLevel=\"4\" pos=\"8\" isHot=\"true\">160032286</fieldElement><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"4\" pos=\"9\" "
		"isOrigin=\"true\" isHot=\"true\">0.80</fieldElement><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\">F</fieldElement><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\">N</fieldElement>"
		"<fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\">2018-01-01</fieldElement><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\">2018</fieldElement><fieldElement uniqueId=\"drugFreeCreditProgramAL\" interestLevel=\"4\" pos=\"0\">0</fieldElement><page compoundKey=\"workersComp/ratingFactors\" isRoster=\"true\" inRosterEditMode=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[{index_10}]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	/*Correlation comment - Do not change!  Original value='2044421492' Name ='HASH_state2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH_state23",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='{CSRF_TOKEN_state2}' Name ='CSRF_TOKEN_state2' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state23",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
	web_submit_data("FrontServlet_122", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingFactors&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState[{index_10}]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN_state21}", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state22}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state22}", ENDITEM, 
		"Name=METHOD", "Value=ProcessEdit", ENDITEM, 
		"Name=NEXT", "Value=Save", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value={compstateid13}", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value={compstateprovcd13}", ENDITEM, 
		"Name=StateRatingFactorState", "Value=KY", ENDITEM, 
		"Name=WorkCompDeductibleAmount", "Value=5000", ENDITEM, 
		"Name=RiskID", "Value=160032286", ENDITEM, 
		"Name=StateRatingFactorAREM", "Value=0.80", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=None", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=F", ENDITEM, 
		"Name=ContingentIndicator", "Value=N", ENDITEM, 
		"Name=RatingEffDate", "Value=2018-01-01", ENDITEM, 
		"Name=RatingEffYear", "Value=2018", ENDITEM, 
		"Name=drugFreeCreditProgramAL", "Value=0", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_10}]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[{index_10}]", ENDITEM, 
		LAST);

	web_custom_request("FrontServlet_123", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state23}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingFactors&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN_state23}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&RateFactorMessage=&RateFactorMultiResultJSON=&WorkCompLineBusiness.WorkCompRateState.%40id=GUID()&WorkCompLineBusiness.WorkCompRateState.StateProvCd.%40id=GUID()&StateRatingFactorState=&StateRatingFactorSRA=&StateRatingFactorWVSUB=&StatusofRateFilingCode=&"
		"ContingentIndicator=&RatingEffDate=&RatingEffYear=&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D&INDEX.WorkCompLineBusiness.WorkCompRateState=WorkCompLineBusiness.WorkCompRateState%5B12%5D", 
       	LAST);

	web_custom_request("IntrapageDTRServlet_57", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/IntrapageDTRServlet", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=text/xml", 
		"Body=<intraPageDTRRequest><workItemId>{WORKITEMID}</workItemId><fieldElement uniqueId=\"RateFactorStandardizationHelperMessage\" interestLevel=\"2\" pos=\"0\"/><fieldElement uniqueId=\"RateFactorMessage\" interestLevel=\"2\" pos=\"1\"/><fieldElement uniqueId=\"RateFactorMultiResultJSON\" interestLevel=\"2\" pos=\"2\"/><fieldElement uniqueId=\"WorkCompLineBusiness.WorkCompRateState.@id\" interestLevel=\"2\" pos=\"3\">GUID()</fieldElement><fieldElement uniqueId=\""
		"WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id\" interestLevel=\"2\" pos=\"4\">GUID()</fieldElement><fieldElement uniqueId=\"StateRatingFactorState\" interestLevel=\"2\" pos=\"5\" isOrigin=\"true\" isHot=\"true\"/><fieldElement uniqueId=\"RiskID\" interestLevel=\"2\" pos=\"8\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorAREM\" interestLevel=\"2\" pos=\"9\" isHot=\"true\"/><fieldElement uniqueId=\"StateRatingFactorMERIT\" interestLevel=\"2\" pos=\"10\" isHot=\"true\"/>"
		"<fieldElement uniqueId=\"StateRatingFactorSRA\" interestLevel=\"2\" pos=\"11\"/><fieldElement uniqueId=\"StateRatingFactorWVSUB\" interestLevel=\"4\" pos=\"14\"/><fieldElement uniqueId=\"StatusofRateFilingCode\" interestLevel=\"2\" pos=\"15\"/><fieldElement uniqueId=\"ContingentIndicator\" interestLevel=\"2\" pos=\"16\"/><fieldElement uniqueId=\"RatingEffDate\" interestLevel=\"2\" pos=\"17\"/><fieldElement uniqueId=\"RatingEffYear\" interestLevel=\"2\" pos=\"18\"/><page compoundKey=\"workersComp/"
		"ratingFactors\" isRoster=\"true\"/><index>WorkCompLineBusiness.WorkCompRateState[12]</index><target>WorkCompPolicyQuoteInqRq</target></intraPageDTRRequest>", 
		LAST);

	web_submit_data("FileUploadServlet_27", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN_state24",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
	web_submit_data("FrontServlet_124", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state23}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=ratingFactors", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state23}", ENDITEM, 
		"Name=METHOD", "Value=Process", ENDITEM, 
		"Name=NEXT", "Value=Continue", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=RateFactorMessage", "Value=", ENDITEM, 
		"Name=RateFactorMultiResultJSON", "Value=", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.@id", "Value=GUID()", ENDITEM, 
		"Name=WorkCompLineBusiness.WorkCompRateState.StateProvCd.@id", "Value=GUID()", ENDITEM, 
		"Name=StateRatingFactorState", "Value=", ENDITEM, 
		"Name=StateRatingFactorSRA", "Value=", ENDITEM, 
		"Name=StateRatingFactorWVSUB", "Value=", ENDITEM, 
		"Name=StatusofRateFilingCode", "Value=", ENDITEM, 
		"Name=ContingentIndicator", "Value=", ENDITEM, 
		"Name=RatingEffDate", "Value=", ENDITEM, 
		"Name=RatingEffYear", "Value=", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[12]", ENDITEM, 
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState", "Value=WorkCompLineBusiness.WorkCompRateState[12]", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_125", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state23}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=flatWaiverWIPage", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state24}", ENDITEM, 
		"Name=METHOD", "Value=Process", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=FlatWaiverWIEntityType", "Value=", ENDITEM, 
		"Name=FlatWaiverWIEntityName", "Value=", ENDITEM, 
		LAST);

    web_url("data_1_1",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN_state24}&rnd=1513768464948&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t146.inf",
		"Mode=HTML",
		LAST);
		
	web_submit_data("FileUploadServlet_28", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_08_StateRating_12_Kentucky",LR_AUTO);


	lr_start_transaction("01_09_FlatwaivrWisconsin");
	
web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN17",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_135", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state23}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=flatWaiverWIPage", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_state24}", ENDITEM, 
		"Name=METHOD", "Value=Process", ENDITEM, 
		"Name=NEXT", "Value=Add", ENDITEM, 
		"Name=DATA_CHANGED", "Value=true", ENDITEM, 
		"Name=FlatWaiverWIEntityType", "Value=ORG", ENDITEM, 
		"Name=FlatWaiverWIEntityName", "Value=Flatwaiver1", ENDITEM, 
		LAST);


	web_submit_data("FrontServlet_136", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state23}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=flatWaiverWIPage", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN17}", ENDITEM, 
		"Name=METHOD", "Value=Process", ENDITEM, 
		"Name=NEXT", "Value=AutoSave", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=FlatWaiverWIEntityType", "Value=", ENDITEM, 
		"Name=FlatWaiverWIEntityName", "Value=", ENDITEM, 
		LAST);


	web_submit_data("FileUploadServlet_29", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN18",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
	
	web_submit_data("FrontServlet_138", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=HASH", "Value={HASH_state23}", ENDITEM, 
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM, 
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM, 
		"Name=PAGE_NAME", "Value=flatWaiverWIPage", ENDITEM, 
		"Name=force_view_on_upload", "Value=false", ENDITEM, 
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN17}", ENDITEM, 
		"Name=METHOD", "Value=Process", ENDITEM, 
		"Name=NEXT", "Value=Continue", ENDITEM, 
		"Name=DATA_CHANGED", "Value=", ENDITEM, 
		"Name=FlatWaiverWIEntityType", "Value=", ENDITEM, 
		"Name=FlatWaiverWIEntityName", "Value=", ENDITEM, 
		LAST);



	web_custom_request("FrontServlet_139", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=HASH={HASH_state23}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingInfo&force_view_on_upload=true&CSRF_TOKEN={CSRF_TOKEN18}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.%40id=GUID()&workCompLocRef=&rateClassList=&annualExposure=&fullTimeEmployees=&partTimeEmployees=", 
		LAST);

	web_submit_data("FileUploadServlet_30", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);
	
lr_end_transaction("01_09_FlatwaivrWisconsin",LR_AUTO);


lr_start_transaction("01_WC_10_RatingInformation");

	

/*Correlation comment - Do not change!  Original value='31aff9438088a93d5c41208fc1bec3c0df1ea3206aa20d2341f3bc324c2edf65' Name ='CSRF_TOKEN19' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN19",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-229362643' Name ='HASH5' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH5",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N123' Name ='COMPID' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=COMPID",
		"LB=WorkCompRateState_WorkCompRateClass_id\" value=\"",
	    "RB=\" />",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
		web_reg_save_param_ex(
		"ParamName=LocationID1",
		"LB=<option value=\"",
	    "RB=\" selected >Wisconsin",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_url("FrontServlet_73",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[{index_7}].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN18}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t123.inf",
		"Mode=HTML",
	    LAST);

	web_url("data_14",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN19}&rnd=1513768418254&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[index_6}].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN18}",
		"Snapshot=t124.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=/AgencyPortal/assets/themes/secura/orangebar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[index_6}].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN18}", ENDITEM,
		"URL=/AgencyPortal/assets/themes/secura/logo.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[index_6}].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN18}", ENDITEM,
		LAST);

	

	web_submit_data("FileUploadServlet_15",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[index_6}].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN18}",
		"Snapshot=t125.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=requestType", "Value=list", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_74",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[index_6}].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN18}",
		"Snapshot=t126.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH5}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingInfo", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN19}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass", "Value=WorkCompLineBusiness.WorkCompRateState[index_6}].WorkCompRateClass[0]", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.@id", "Value={COMPID}", ENDITEM,
		"Name=workCompLocRef", "Value={LocationID1}", ENDITEM,
		"Name=rateClassList", "Value=", ENDITEM,
		"Name=annualExposure", "Value=", ENDITEM,
		"Name=fullTimeEmployees", "Value=", ENDITEM,
		"Name=partTimeEmployees", "Value=", ENDITEM,
		LAST);

//	web_submit_data("FrontServlet_75",
//		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
//		"Method=POST",
//		"TargetFrame=",
//		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[4].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN18}",
//		"Snapshot=t127.inf",
//		"Mode=HTML",
//		ITEMDATA,
//		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
//		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
//		"Name=PAGE_NAME", "Value=ratingInfo", ENDITEM,
//		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
//		"Name=METHOD", "Value=Process", ENDITEM,
//	
	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text=agencyportal", 
		LAST);

/*Correlation comment - Do not change!  Original value='7266dd46b84599886a49665ca42931bc5e22c776d0edf05f96ca1d1abbe76df1' Name ='CSRF_TOKEN21' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN21",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);
//		
//		web_reg_find("Text=58%",
//             //"Scope=Body",
//             LAST);
//             

/*Correlation comment - Do not change!  Original value='1208964355' Name ='HASH9' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH9",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_77",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[4].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN18}",
		"Snapshot=t129.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH5}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingInfo", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN19}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=Save", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass", "Value=WorkCompLineBusiness.WorkCompRateState[4].WorkCompRateClass[0]", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.@id", "Value={COMPID}", ENDITEM,
		"Name=workCompLocRef", "Value={LocationID1}", ENDITEM,
		"Name=rateClassList", "Value=8810/Clerical Office Employees NOC", ENDITEM,
		"Name=RatingClassIfAny", "Value=YES", ENDITEM,
		"Name=fullTimeEmployees", "Value=20", ENDITEM,
		"Name=partTimeEmployees", "Value=", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/custom/select2/select2.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		LAST);

	web_url("data_15",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN21}&rnd=1513768440404&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t130.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("FrontServlet_78",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t131.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH9}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingInfo&force_view_on_upload=true&CSRF_TOKEN={CSRF_TOKEN21}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.%40id=GUID()&workCompLocRef=&rateClassList=&annualExposure=&fullTimeEmployees=&partTimeEmployees=",
		LAST);


	web_submit_data("FileUploadServlet_16", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t133.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);


/*Correlation comment - Do not change!  Original value='-1314701783' Name ='HASH6' Type ='Manual'*/
web_reg_save_param_ex(
		"ParamName=HASH6",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);
		
/*Correlation comment - Do not change!  Original value='0ca348875e37d44bb80659488e9f150433d184bd4e803668f69273b2a49f9605' Name ='CSRF_TOKEN21_1' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN21_1",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='N137' Name ='compid2' Type ='Manual'*/
	web_reg_save_param_attrib(
		"ParamName=compid2",
		"TagName=input",
		"Extract=value",
		"Name=WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.@id",
		"Id=WorkCompLineBusiness_WorkCompRateState_WorkCompRateClass_id",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_url("FrontServlet_80",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t134.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}", ENDITEM,
		"URL=assets/themes/secura/logo.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}", ENDITEM,
		"URL=assets/custom/select2/select2.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", "Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("FrontServlet_81",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}",
		"Snapshot=t135.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH6}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingInfo", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN21_1}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass", "Value=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.@id", "Value={compid2}", ENDITEM,
		"Name=workCompLocRef", "Value={workCompLocRef}", ENDITEM,
		"Name=rateClassList", "Value=", ENDITEM,
		"Name=annualExposure", "Value=", ENDITEM,
		"Name=fullTimeEmployees", "Value=", ENDITEM,
		"Name=partTimeEmployees", "Value=", ENDITEM,
		LAST);

	web_url("data_16",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN21_1}&rnd=1513768445071&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}",
		"Snapshot=t136.inf",
		"Mode=HTML",
		LAST);


	web_submit_data("FileUploadServlet_17",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}",
		"Snapshot=t138.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=requestType", "Value=list", ENDITEM,
		LAST);

/*Correlation comment - Do not change!  Original value='0243775016ee7d26190c9309684c486efede39a50ca0ff934120c8fd343e87d2' Name ='CSRF_TOKEN25' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN25",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='-93759474' Name ='HASH7' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH7",
		"LB=id=\"HASH\" value=\"",
	    "RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_83",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?PAGE_NAME=ratingInfo&METHOD=Display&TRANSACTION_NAME=workersComp&WORKITEMID={WORKITEMID}&INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]&EDIT=true&CSRF_TOKEN={CSRF_TOKEN21}",
		"Snapshot=t139.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH6}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingInfo", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN21_1}", ENDITEM,
		"Name=METHOD", "Value=ProcessEdit", ENDITEM,
		"Name=NEXT", "Value=Save", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass", "Value=WorkCompLineBusiness.WorkCompRateState[1].WorkCompRateClass[0]", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.@id", "Value={compid2}", ENDITEM,
		"Name=workCompLocRef", "Value={workCompLocRef}", ENDITEM,
		"Name=rateClassList", "Value=8601/Architect", ENDITEM,
		"Name=annualExposure", "Value=250", ENDITEM,
		"Name=fullTimeEmployees", "Value=", ENDITEM,
		"Name=partTimeEmployees", "Value=2", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		"URL=assets/custom/select2/select2.png", ENDITEM,
		LAST);

	web_url("data_17",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN25}&rnd=1513768459874&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t140.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("FrontServlet_84",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t141.inf",
		"Mode=HTML",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"Body=HASH={HASH7}&WORKITEMID={WORKITEMID}&TRANSACTION_NAME=workersComp&PAGE_NAME=ratingInfo&force_view_on_upload=false&CSRF_TOKEN={CSRF_TOKEN25}&METHOD=Process&NEXT=AutoSave&DATA_CHANGED=&WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.%40id=GUID()&workCompLocRef=&rateClassList=&annualExposure=&fullTimeEmployees=&partTimeEmployees=",
		LAST);

	web_submit_data("FileUploadServlet_18", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t142.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	/*web_submit_data("FrontServlet_85",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t143.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN25}", ENDITEM,
		LAST);*/

	
/*Correlation comment - Do not change!  Original value='3ae3b591b5e64365132b686ac9653a07cab0cb99001d596cc1cb2fb55ded08b8' Name ='CSRF_TOKEN26' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN26",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_86",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t144.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH7}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=ratingInfo", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN25}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompRateState.WorkCompRateClass.@id", "Value=GUID()", ENDITEM,
		"Name=workCompLocRef", "Value=", ENDITEM,
		"Name=rateClassList", "Value=", ENDITEM,
		"Name=annualExposure", "Value=", ENDITEM,
		"Name=fullTimeEmployees", "Value=", ENDITEM,
		"Name=partTimeEmployees", "Value=", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("FrontServlet_87",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t145.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH7}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=includedExcludedIndividuals", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN26}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=WorkCompIndividualsId", "Value=", ENDITEM,
		"Name=WorkCompIndividualsSystemId", "Value=", ENDITEM,
		"Name=workCompIndividualsLocRef", "Value=", ENDITEM,
		"Name=WorkCompIndividualsCommlName", "Value=", ENDITEM,
		"Name=WorkCompIndividualsTitle", "Value=", ENDITEM,
		"Name=WorkCompIndividualsOwnershipPercent", "Value=", ENDITEM,
		"Name=WorkCompIndividualsDOB", "Value=", ENDITEM,
		"Name=WorkCompIndividualsRemuneration", "Value=", ENDITEM,
		"Name=WorkCompIndividualsDuties", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompIndividuals", "Value=WorkCompLineBusiness.WorkCompIndividuals[0]", ENDITEM,
		LAST);

	web_url("data_18",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN26}&rnd=1513768464948&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t146.inf",
		"Mode=HTML",
		LAST);


	/*web_submit_data("FrontServlet_88",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t147.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=includedExcludedIndividuals", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN26}", ENDITEM,
		LAST);*/

	web_submit_data("FileUploadServlet_19", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t148.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_WC_10_RatingInformation",LR_AUTO);


	lr_start_transaction("01_WC_11_PremiumIndication");
	
	
	/*Correlation comment - Do not change!  Original value='27983920344ca7d571b78406c889b2010acf6d996ee16d760f930d05cbc117bf' Name ='CSRF_TOKEN_29' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=CSRF_TOKEN_29",
		"LB='CSRF_TOKEN': '",
		"RB='",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_156",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t222.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=premiumIndication", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=pageFlag", "Value=Y", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN26}", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		LAST);




	web_submit_data("FrontServlet_157",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t223.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=includedExcludedIndividuals", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_29}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_158",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t224.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=0", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=includedExcludedIndividuals", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_29}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=WorkCompIndividualsId", "Value=", ENDITEM,
		"Name=WorkCompIndividualsSystemId", "Value=", ENDITEM,
		"Name=workCompIndividualsLocRef", "Value=", ENDITEM,
		"Name=WorkCompIndividualsCommlName", "Value=", ENDITEM,
		"Name=WorkCompIndividualsTitle", "Value=", ENDITEM,
		"Name=WorkCompIndividualsOwnershipPercent", "Value=", ENDITEM,
		"Name=WorkCompIndividualsDOB", "Value=", ENDITEM,
		"Name=WorkCompIndividualsRemuneration", "Value=", ENDITEM,
		"Name=WorkCompIndividualsDuties", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompIndividuals", "Value=WorkCompLineBusiness.WorkCompIndividuals[0]", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_23", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t225.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_url("data_22",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN_29}&rnd=1513937536161&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t226.inf",
		"Mode=HTML",
		LAST);
	
	
	    lr_end_transaction("01_WC_11_PremiumIndication",LR_AUTO);
		
	    lr_start_transaction("01_WC_12_IndividualsIncluded");
     	

/*Correlation comment - Do not change!  Original value='1ec91f7484153af1b41874ec5d5d02de612b8af3234a5e92b09ccfe15cbb1adc' Name ='CSRF_TOKEN31' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN31",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_161",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t229.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=0", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=includedExcludedIndividuals", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN_29}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Add", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=WorkCompIndividualsId", "Value=", ENDITEM,
		"Name=WorkCompIndividualsSystemId", "Value=", ENDITEM,
		"Name=workCompIndividualsLocRef", "Value={LocationID1}", ENDITEM,
		"Name=WorkCompIndividualsCommlName", "Value=ARIZONA", ENDITEM,
		"Name=WorkCompIndividualsIncExcCd", "Value=I", ENDITEM,
		"Name=WorkCompIndividualsFormInd", "Value=YES", ENDITEM,
		"Name=WorkCompIndividualsTitle", "Value=Ptnr", ENDITEM,
		"Name=WorkCompIndividualsOwnershipPercent", "Value=", ENDITEM,
		"Name=WorkCompIndividualsDOB", "Value={EffectiveDate}", ENDITEM,
		"Name=WorkCompClassCode", "Value=", ENDITEM,
		"Name=WorkCompIndividualsRemuneration", "Value=", ENDITEM,
		"Name=WorkCompIndividualsDuties", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompIndividuals", "Value=WorkCompLineBusiness.WorkCompIndividuals[0]", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		LAST);

	web_url("data_23",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN31}&rnd=1513937574047&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t230.inf",
		"Mode=HTML",
		LAST);


	web_submit_data("FrontServlet_162",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t231.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=0", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=includedExcludedIndividuals", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN31}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=WorkCompIndividualsId", "Value=", ENDITEM,
		"Name=WorkCompIndividualsSystemId", "Value=", ENDITEM,
		"Name=workCompIndividualsLocRef", "Value=", ENDITEM,
		"Name=WorkCompIndividualsCommlName", "Value=", ENDITEM,
		"Name=WorkCompIndividualsTitle", "Value=", ENDITEM,
		"Name=WorkCompIndividualsOwnershipPercent", "Value=", ENDITEM,
		"Name=WorkCompIndividualsDOB", "Value=", ENDITEM,
		"Name=WorkCompIndividualsRemuneration", "Value=", ENDITEM,
		"Name=WorkCompIndividualsDuties", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompIndividuals", "Value=WorkCompLineBusiness.WorkCompIndividuals[1]", ENDITEM,
		EXTRARES,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_24", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t232.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

/*Correlation comment - Do not change!  Original value='bcaff52ad32bdfae749a3106459cd9a450de76fb556bce27d8b59d71090e0e32' Name ='CSRF_TOKEN32' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=CSRF_TOKEN32",
		"LB='CSRF_TOKEN': '",
		"RB='",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_163",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t233.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=includedExcludedIndividuals", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN31}", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		LAST);




	web_url("data_24",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN32}&rnd=1513937579506&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t235.inf",
		"Mode=HTML",
		LAST);



	web_submit_data("FrontServlet_165",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t236.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=0", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=questionnaire", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN32}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=SECURA_QS_R1_QS81", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS85", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS101", "Value=NO", ENDITEM,
		LAST);


	web_submit_data("FileUploadServlet_25", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t238.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);
	lr_end_transaction("01_WC_12_IndividualsIncluded",LR_AUTO);

	
	lr_start_transaction("01_WC_13_UnderwritingQuestions");

	/*web_submit_data("FrontServlet_101",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t165.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=questionnaire", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN29}", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_102",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t166.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=questionnaire", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN29}", ENDITEM,
		LAST);*/

web_submit_data("FrontServlet_167",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t239.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=questionnaire", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN32}", ENDITEM,
		LAST);



	web_submit_data("FrontServlet_170",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=1",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t242.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=0", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=questionnaire", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN32}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=WCUWQuestionnaire1", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire2", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire3", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire4", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire5", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS81", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS85", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS101", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire6", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire7", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire8", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire9", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire10", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire11", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire12", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire13", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire14", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire15", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire16", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire17", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire18", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire20", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire21", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire22", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire23", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS75", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS77", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS83", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS87", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS89", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS91", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS93", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS99", "Value=NO", ENDITEM,
		LAST);



/*Correlation comment - Do not change!  Original value='4fb97db5ed92cd455d0ecf098709d92c742721b7f39b4476245f63dd259b93aa' Name ='CSRF_TOKEN33' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN33",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

/*Correlation comment - Do not change!  Original value='905280544' Name ='HASH8' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=HASH8",
		"LB=id=\"HASH\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_172",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t244.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value=0", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=questionnaire", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN32}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=true", ENDITEM,
		"Name=WCUWQuestionnaire1", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire2", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire3", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire4", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire5", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS81", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS85", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS101", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire6", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire7", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire8", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire9", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire10", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire11", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire12", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire13", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire14", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire15", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire16", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire17", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire18", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire20", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire21", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire22", "Value=NO", ENDITEM,
		"Name=WCUWQuestionnaire23", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS75", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS77", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS83", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS87", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS89", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS91", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS93", "Value=NO", ENDITEM,
		"Name=SECURA_QS_R1_QS99", "Value=NO", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		LAST);

	web_url("data_25",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN33}&rnd=1513937650117&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t245.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("FrontServlet_173",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t246.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH8}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=priorCarrierLosses", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN33}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompLossOrPriorPolicy.EffectiveDt", "Value=", ENDITEM,
		"Name=LossCarrier", "Value=", ENDITEM,
		"Name=LossPolicyNumber", "Value=", ENDITEM,
		"Name=LossAnnualPremium", "Value=", ENDITEM,
		"Name=LossExpMod", "Value=", ENDITEM,
		"Name=LossNoOfClaims", "Value=", ENDITEM,
		"Name=LossAmountPaid", "Value=", ENDITEM,
		"Name=LossAmountReserved", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompLossOrPriorPolicy", "Value=WorkCompLineBusiness.WorkCompLossOrPriorPolicy[0]", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_26", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t247.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	web_submit_data("FrontServlet_174",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t248.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=priorCarrierLosses", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN33}", ENDITEM,
		LAST);


	lr_end_transaction("01_WC_13_UnderwritingQuestions",LR_AUTO);

	lr_start_transaction("01_WC_14_PRIORCARRIER");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	/*web_submit_data("FrontServlet_119",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t185.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=priorCarrierLosses", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN30}", ENDITEM,
		LAST);*/

	/*Correlation comment - Do not change!  Original value='4400bbb218b811b020962c3e21089eaab81ab6c77ed6decce70a5e43d5d8aded' Name ='CSRF_TOKEN34' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CSRF_TOKEN34",
		"RegExp='CSRF_TOKEN':\\ '(.*?)'\\ \\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/FrontServlet*",
		LAST);

	web_submit_data("FrontServlet_175",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t249.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH8}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=priorCarrierLosses", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN33}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=Continue", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=WorkCompLineBusiness.WorkCompLossOrPriorPolicy.EffectiveDt", "Value=", ENDITEM,
		"Name=LossCarrier", "Value=", ENDITEM,
		"Name=LossPolicyNumber", "Value=", ENDITEM,
		"Name=LossAnnualPremium", "Value=", ENDITEM,
		"Name=LossExpMod", "Value=", ENDITEM,
		"Name=LossNoOfClaims", "Value=", ENDITEM,
		"Name=LossAmountPaid", "Value=", ENDITEM,
		"Name=LossAmountReserved", "Value=", ENDITEM,
		"Name=INDEX.WorkCompLineBusiness.WorkCompLossOrPriorPolicy", "Value=WorkCompLineBusiness.WorkCompLossOrPriorPolicy[0]", ENDITEM,
		EXTRARES,
		"URL=assets/fonts/proxima-nova/ProximaNova-Reg-webfont.eot", ENDITEM,
		LAST);

	web_url("data_26",
		"URL=https://qa-agentlink.secura.net/AgencyPortal/api/workitemassistants/data?WORKITEMID={WORKITEMID}&CSRF_TOKEN={CSRF_TOKEN34}&rnd=1513937667956&transaction_id=workersComp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t250.inf",
		"Mode=HTML",
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("FrontServlet_176",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet?ISAUTOSAVE=0",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t251.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=HASH", "Value={HASH8}", ENDITEM,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=billingContactInfo", ENDITEM,
		"Name=force_view_on_upload", "Value=false", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN34}", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=NEXT", "Value=AutoSave", ENDITEM,
		"Name=DATA_CHANGED", "Value=", ENDITEM,
		"Name=ACName", "Value=", ENDITEM,
		"Name=ACPhone", "Value=", ENDITEM,
		"Name=ACMobile", "Value=", ENDITEM,
		"Name=ACEmail", "Value=", ENDITEM,
		"Name=ICName", "Value=", ENDITEM,
		"Name=ICPhone", "Value=", ENDITEM,
		"Name=ICMobile", "Value=", ENDITEM,
		"Name=ICEmail", "Value=", ENDITEM,
		"Name=CCName", "Value=", ENDITEM,
		"Name=CCPhone", "Value=", ENDITEM,
		"Name=CCMobile", "Value=", ENDITEM,
		"Name=CCEmail", "Value=", ENDITEM,
		EXTRARES,
		"URL=assets/themes/secura/colorbar.png", ENDITEM,
		LAST);

	web_submit_data("FrontServlet_177",
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Method=POST",
		"TargetFrame=",
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet",
		"Snapshot=t252.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=WORKITEMID", "Value={WORKITEMID}", ENDITEM,
		"Name=TRANSACTION_NAME", "Value=workersComp", ENDITEM,
		"Name=PAGE_NAME", "Value=billingContactInfo", ENDITEM,
		"Name=NEXT", "Value=WorkItemLock", ENDITEM,
		"Name=METHOD", "Value=Process", ENDITEM,
		"Name=CSRF_TOKEN", "Value={CSRF_TOKEN34}", ENDITEM,
		EXTRARES,
		"URL=assets/themes/secura/orangebar.png", ENDITEM,
		"URL=assets/themes/secura/logo.png", ENDITEM,
		"URL=assets/fonts/font-awesome/fontawesome-webfont.eot", ENDITEM,
		LAST);

	web_submit_data("FileUploadServlet_27", 
		"Action=https://qa-agentlink.secura.net/AgencyPortal/FileUploadServlet", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t253.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=requestType", "Value=list", ENDITEM, 
		LAST);

	lr_end_transaction("01_WC_14_PRIORCARRIER",LR_AUTO);

	lr_start_transaction("01_WC_15_Logoff");
	
	web_url("ProcessLogoff", 
		"URL=https://qa-agentlink.secura.net/AgencyPortal/ProcessLogoff", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgencyPortal/FrontServlet", 
		"Snapshot=t193.inf", 
		"Mode=HTML", 
		LAST);



	web_url("Log Out", 
		"URL=https://qa-agentlink.secura.net/AgentLink/Authenticate/LogOut", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa-agentlink.secura.net/AgentLink", 
		"Snapshot=t194.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("01_WC_15_Logoff",LR_AUTO);

	return 0;
}