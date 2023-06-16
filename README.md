
# Moodle REST API Wrapper for Unreal Engine 5

![Logo](https://raw.githubusercontent.com/CAP160-GameTeam/CAP160Img/main/CAP160_bleu.png)

Control any moodle server directly from Unreal Engine 5 (based on Moodle 4.1.2).

No C++ coding required, everything can be managed via blueprints.

Blueprintable GetValueFromJsonString node that can return part of a JSON server response.

Fully asynchronous nodes enabling integrating Moodle's extensive API into any UI.

// --- Querying a User Token --- //

All API calls need a user token to be used correctly. 

This user token can be retrieved by the node "query_token_from_user", by providing it with the URL of your server, a username, and a 
password. 

This node, as they all do, returns a raw response, which can be parsed with the "GetValueFromJsonString" node.

By giving this node a key that is contained in the raw response (here, 'token'), only the value bound to this key will be returned.

This is useful to extract the id of a newly-created account, the shortname of a course, or as it is done here, a user token, from a raw server response.


![Logo](https://raw.githubusercontent.com/CAP160-GameTeam/CAP160Img/e3430918da8c6711aabcb3d0025a53e62a399600/MoodleTokenExample.png)

