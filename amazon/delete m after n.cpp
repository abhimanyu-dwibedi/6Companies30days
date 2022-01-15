  static void linkdelete(Node head, int m, int n)
    {
        // your code here
        Node p=head;
        Node del=head;
        while (head!=null){
            for (int i=0;i< m-1 && head!=null;i++){
                head=head.next;
            }
            for (int i=0;i<m+n && del!=null;i++){
                del=del.next;
            }
            if (head==null)break;
            if (del==null &&  head.next!=null){
                head.next=null;
                break;
            }
            head.next=del;
            if (head!=null)head=head.next;
        }