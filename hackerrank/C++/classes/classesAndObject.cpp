// Write your Student class here
class Student {
  private:
    struct scores{
        int s1;
        int s2;
        int s3;
        int s4;
        int s5;
    };
    scores st;
   public:
    void input(){
        
        cin>>st.s1;
        cin>>st.s2;
        cin>>st.s3;
        cin>>st.s4;
        cin>>st.s5;
    }
    
    int calculateTotalScore() {
        return (st.s1+st.s2+st.s3+st.s4+st.s5);
    }
};
