using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using entities.Concrete;
namespace Bll.Abstract
{
    public interface IYayinEviBll
    {
        List<yayinEvi> getAll();
        yayinEvi getOneById(int id);
        void Update(yayinEvi yayinEvi);
        void Add(yayinEvi yayinEvi);
        void Delete(yayinEvi yayinEvi);
    }
}
