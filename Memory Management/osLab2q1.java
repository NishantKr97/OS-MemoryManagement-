import java.util.*;  

class F{
	int allocatedMem;
	Page page;
	F(int i){
		this.allocatedMem=i;
	}
}

class Page{
	int processID;
	int page_no;
	int address=-1;
	Page(int id,int page_no){
		this.processID=id;
		this.page_no=page_no;
	}
}

class Process{
	int id;
	int size;
	LinkedList<Page> pages=new LinkedList<Page>();
	LinkedList<F> frames=new LinkedList<F>();
	private Page page;
	Process(int id,int a){
		this.id=id;
		this.size=a;
		int p=(this.size/p1.p) + (((this.size%p1.p)>0)?1:0);
		for(int i=0;i<p;i++){
			page=new Page(id,i+1);
			pages.add(page);
		}
	}
	
	void pagify(){
		for(Page p: pages){
			if(p.address==-1)
				for(int i=0;i<p1.frame.length;i++)
					if(p1.frame[i].allocatedMem==0){
						p1.frame[i].allocatedMem=1;
						p1.frame[i].page=p;
						p.address=i;
						this.frames.add(p1.frame[i]);
						break;
					}
		}
	}
}


class p1{
	static int p;
	static F []frame;
	static List<Process> process_list;
	public static void main(String args[]){
		int process_count=0;
		process_list=new LinkedList<Process>();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter size of pages.");
		p=sc.nextInt();
		System.out.println("Enter total no. of frames in memory.");
		int total_frames=sc.nextInt();
		frame=new F [total_frames];
		for(int i=0;i<total_frames;i++){
			frame[i]=new F (0);
		}
		
		int choice=1;
		Process pr;
		while(choice!=0){
			System.out.println("The Fs are:\nF No.\tProcess ID\t Page No.");
			int it=0;
			for(F f:frame){
				System.out.print(it+"\t\t");
				it++;
				if(f.allocatedMem==1)
					System.out.println(f.page.processID+"\t\t "+f.page.page_no);
				else
					System.out.println("free \t\t free");
			}
			System.out.println("\n1.Add Process.\n2.Remove process.\n0.Exit");
			choice=sc.nextInt();
			switch(choice){
				case 1:
					process_count++;
					System.out.println("Enter Size of process.");
					pr=new Process(process_count,sc.nextInt());
					process_list.add(pr);
					pr.pagify();
					break;
				case 2:
					System.out.println("Processes:");
					for(int i=0;i<process_list.size();i++){
						System.out.println(i+" : "+process_list.get(i).size);
					}
					int delete_index=sc.nextInt();
					Process delete_process=process_list.get(delete_index);
					for(F f: delete_process.frames){
						f.allocatedMem=0;
						f.page=null;
					}
					process_list.remove(delete_index);
					for(int i=delete_index;i<process_list.size();i++){
						process_list.get(i).pagify();
					}

				default: break;
			}
		}
		
		
	}
}