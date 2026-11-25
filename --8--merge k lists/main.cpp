ListNode* mergeKLists(vector<ListNode*>& lists) {

    while (lists.size() > 1) {

        vector<ListNode*> merged;

        for (size_t i = 0; i < lists.size(); i += 2) {

            if (i + 1 < lists.size()) {
                merged.push_back(
                    mergeTwoLists(lists[i], lists[i + 1])
                );
            } 
            else {
                merged.push_back(lists[i]);
            }
        }

        lists = merged;
    }

    return lists.empty() ? nullptr : lists[0];
}